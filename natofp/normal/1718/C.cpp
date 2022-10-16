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
#define mt make_tuple

using namespace std;

const int nax = 2e5 + 5;
int n, q;
int a[nax];
vector<int> divs;
vector<ll> sum[2005];
multiset<ll> alive;

ll calc_ans(){
    return (*alive.rbegin());
}

void del(ll x){
    alive.erase(alive.find(x));
}

void add(ll x){
    alive.insert(x);
}

set<int> exist;

void solve(){
    exist.clear();
    alive.clear();
    divs.clear();
    cin >> n >> q;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=n-1;i>=1;i--){
        if(n % i == 0){
            int dl = n / i;
            bool ok = true;
            for(int x : exist){
                if(dl % x == 0) ok = false;
            }
            if(ok){
                divs.pb(i);
                exist.insert(dl);
            }
        }
    }
    sort(divs.begin(), divs.end());
    for(int i=0;i<divs.size();i++){
        int d = divs[i];
        sum[i].clear();
        sum[i].resize(0);
        sum[i].resize(d);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<divs.size();j++){
            int d = divs[j];
            sum[j][i % d] += a[i];
        }
    }
    for(int j=0;j<divs.size();j++){
        int d = divs[j];
        for(int i=0;i<d;i++){
            add(sum[j][i] * d);
        }
    }
    cout << calc_ans() << "\n";
    for(int c=1;c<=q;c++){
        int p, x; cin >> p >> x;
        p--;
        for(int j=0;j<divs.size();j++){
            int d = divs[j];
            del(sum[j][p % d] * d);
            sum[j][p % d] += (x - a[p]);
            add(sum[j][p % d] * d);
        }
        a[p] = x;
        cout << calc_ans() << "\n";
    }
}

ll cnt[nax];



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}