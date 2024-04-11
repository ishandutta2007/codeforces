#include<bits/stdc++.h>
#define int long long

using namespace std;
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

// using namespace std;
const int maxn=200007;
int n;
int a[maxn][5];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        int cand=0;
        rep(i,n) rep(j,5) cin>>a[i][j];
        auto good=[&](int u,int v){
            int count=0;
            rep(j,5){
                if (a[u][j]<a[v][j]) count++;
            }
            return count>2;
        };
        rep1(i,n-1){
            if (!good(cand,i)) cand=i;
        }
        bool ok=1;
        rep(i,n){
            if (cand==i) continue;
            if (!good(cand,i)) ok=0;
        }
        if (ok) cout<<cand+1<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}