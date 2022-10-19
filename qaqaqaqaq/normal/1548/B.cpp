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

const int maxn=200007;
int n,m,q;
int a[maxn],diff[maxn],b[maxn][20];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        rep1(i,n) cin>>a[i];
        rep1(i,n-1) diff[i]=abs(a[i+1]-a[i]);
        bool ok=0;
        rep1(i,n-1) {b[i][0]=diff[i]; if (diff[i]>1) ok=1;}
        if (!ok) {cout<<"1\n"; continue;}
        rep1(j,18){
            rep1(i,n){
                if (i+(1<<j)<=n) b[i][j]=__gcd(b[i][j-1],b[i+(1<<j-1)][j-1]);
                else b[i][j]=1;
            }
        }
        int ans=0;
        rep1(i,n-1){
            int nxt=i, g=0;
            for (int j=18;j>-1;--j){
                if (nxt<n&&__gcd(g,b[nxt][j])>1) {
                    g=__gcd(g,b[nxt][j]),nxt+=(1<<j);
                }
            }
            ans=max(ans,nxt-i);
            // cout<<i<<" "<<nxt<<" "<<diff[i]<<endl;
        }
        cout<<ans+1<<"\n";
    }
}