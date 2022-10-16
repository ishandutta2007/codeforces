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

const int nax = 1e6 + 5;
bool prime[nax];

void prep(){
    for(int i=1;i<nax;i++) prime[i] = true;
    prime[1] = false;
    for(int i=2;i<nax;i++){
        for(int j=i*2;j<nax;j+=i){
            prime[j] = false;
        }
    }
}

int a[nax];
int n, e;

void solve(){
    cin >> n >> e;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll ans = 0;
    for(int i=0;i<e;i++){
        vector<int> v;
        int p = i;
        if(p == 0) p = e;
        for(int j=p;j<=n;j+=e){
            v.pb(a[j]);
        }
        for(int j=0;j<v.size();j++){
            if(prime[v[j]]){
                int lft = j;
                int rgt = j;
                while(lft > 0 && v[lft - 1] == 1) lft -= 1;
                while(rgt < v.size() - 1 && v[rgt + 1] == 1) rgt += 1;
                ll l1 = j - lft;
                ll l2 = rgt - j;
                ans += (l1 * l2) + l1 + l2;
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}