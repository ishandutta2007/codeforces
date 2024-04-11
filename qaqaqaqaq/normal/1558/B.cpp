#include<bits/stdc++.h>
// #define int long long
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

const int maxn=4000007;
const int mod=998244353;

int n,m;
int f[maxn],g[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int sum=0;
	for (int i=1;i<=n;++i){
		if (i>1){
			g[i]=(g[i-1]+g[i])%m;
			f[i]=(g[i]+sum)%m;
			sum=(sum+f[i])%m;
		}
		else{
			f[i]=sum=1;
		}
		for (int j=2;i*j<=n;++j){
			g[i*j]=(g[i*j]+f[i])%m;
			g[min((i+1)*j,n+2)]=(g[min((i+1)*j,n+2)]-f[i]+m)%m;
		}	
	}
	cout<<f[n];
	return 0;
}