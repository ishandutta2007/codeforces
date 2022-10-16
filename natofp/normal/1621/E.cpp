#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 1e5 + 5;
int n, m;
ll a[nax];
vector<int> stu[nax];

int roz;
const int DUZO = 2e6;

int added[DUZO];
int tree[DUZO];

void ini(){
    roz = 1;
    while(roz <= m + 1) roz *= 2;
    roz *= 2;

    for(int i=0;i<roz;i++){
        added[i] = 0;
        tree[i] = 0;
    }
}

void add(int lo, int hi, int u, int a, int b, int v){
    if(lo == a && b == hi){
        added[u] += v;
        tree[u] += v;
        return;
    }
    if(b <= a) return;
    int mid = (lo + hi) / 2;
    add(lo, mid, u * 2, a, min(b, mid), v);
    add(mid, hi , u * 2 + 1, max(a, mid), b , v);
    tree[u] = min(tree[u * 2], tree[u * 2 + 1]) + added[u];
}

int ileduzych[nax];


void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) stu[i].clear();
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    n = m;
    for(int i=1;i<=m;i++){
        int k; cin >> k;
        for(int j=0;j<k;j++){
            int x; cin >> x;
            stu[i].pb(x);
        }
    }
    ini();
    for(int i=1;i<=m;i++){
        add(0,roz/2,1,i,i+1,-(m+1-i));
    }
    for(int i=1;i<=m;i++){
        ll suma = 0;
        for(int x : stu[i]) suma += x;
        ll cnt = stu[i].size();
        int lo = 1;
        int hi = n;
        ll stary = a[1];
        if(stary * cnt < suma){
            ileduzych[i] = 0;
            continue;
        }

        while(lo + 1 < hi){
            int mid = (lo + hi) / 2;
            ll stary = a[mid];
            if(stary * cnt >= suma) lo = mid;
            else hi = mid;
        }
        ll odp = lo;
        stary = a[hi];
        if(stary * cnt >= suma) odp = hi;
        ileduzych[i] = odp;
    }
    for(int i=1;i<=m;i++){
        add(0,roz/2,1,1,ileduzych[i]+1,1);
    }
    vector<char> ans;

    for(int i=1;i<=m;i++){
        add(0,roz/2,1,1,ileduzych[i]+1,-1);
        ll suma = 0;
        ll cnt = 0;
        for(int x : stu[i]){
            cnt += 1;
            suma += x;
        }

        for(int x : stu[i]){
            cnt -= 1;
            suma -= x;

            int lo = 1;
            int hi = n;
            ll odp = -666;
            ll stary = a[1];
            if(stary * cnt < suma){
                odp = 0;
            }

            else{
                while(lo + 1 < hi){
                    int mid = (lo + hi) / 2;
                    ll stary = a[mid];
                    if(stary * cnt >= suma) lo = mid;
                    else hi = mid;
                }
                odp = lo;
                stary = a[hi];
                if(stary * cnt >= suma) odp = hi;
            }

            add(0,roz/2,1,1,odp+1,1);
            ll w = tree[1];

            if(w >= 0) ans.pb('1');
            else ans.pb('0');
            add(0,roz/2,1,1,odp+1,-1);

            suma += x;
            cnt += 1;
        }

        add(0,roz/2,1,1,ileduzych[i]+1,1);
    }
    for(char cur : ans) cout << cur;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}