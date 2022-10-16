#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

bool cmp(pii one, pii two){
    return min(one.st, one.nd) < min(two.st, two.nd);
}

void no(){
    cout << -1 << "\n";
    exit(0);
}

vector<pii> a;
int n;
int solve(int lo, int hi){
    int one = 1e9;
    int two = 1e9;
    int cost = 0;
    int len = hi - lo + 1;
    for(int i=lo;i<=hi;i++){
        int akt = a[i].st;
        if(akt > n){
            // put in first
            if(akt < one){
                one = akt;
            }
            else{
                if(akt >= two) return 1e9;
                two = akt;
                cost++;
            }
        }
        else{
            akt = a[i].nd;
            if(akt < one){
                one = akt;
                cost++;
            }
            else{
                if(akt >= two) return 1e9;
                two = akt;
            }
        }
    }
    return min(cost, len - cost);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x,y; cin >> x >> y;
        a.pb(mp(x, y));
        if(max(x,y) <= n){
            no();
        }
    }
    set<int> coming;
    for(int i=n+1;i<=n*2;i++) coming.insert(i);
    sort(a.begin(), a.end(), cmp);
    ll ans = 0;
    for(int i=0;i<n;i++){
        vector<int> cur = {};
        for(int j=i;j<n;j++){
            int akt = a[j].st;
            if(akt <= n) akt = a[j].nd;
            cur.pb(akt);
            coming.erase(akt);
            if(coming.size()){
                auto it = coming.rbegin();
                int lft = n - j - 1;
                if((*it) - lft == n){
                    break;
                }
            }
            else break;
        }
        ans += solve(i, i + cur.size() - 1);
        i += cur.size() - 1;
    }
    if(ans >= 1e9){
        no();
    }
    cout << ans << "\n";
    return 0;
}