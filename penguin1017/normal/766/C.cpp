#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
using namespace std;
const int N=2e3+9;
const ll mod=1e9+7;
char s[N];
int maxn[N],a[26];
ll dp[N];
int main(){
	int n;
	scanf("%d%s",&n,s+1);
	rep(i,0,26)scanf("%d",&a[i]);
	maxn[n]=n;
	rep(i,1,n+1){
		maxn[i]=min(a[s[i]-'a']+i-1,n);
		rep(j,i+1,maxn[i]+1){
			int len=j-i+1;
			if(len>a[s[j]-'a']){
				maxn[i]=j-1;
				break;
			}
			else{
				maxn[i]=min(maxn[i],a[s[j]-'a']+i-1);
			}
		}
	}
	dp[0]=1;
	rep(i,1,n+1){
		rep(j,1,i+1)dp[i]+=(maxn[j]>=i)?dp[j-1]:0;
		dp[i]%=mod;
	}
	printf("%lld\n",dp[n]);
	int ans=0;
	rep(i,1,n+1)ans=max(maxn[i]-i,ans);
	printf("%d\n",ans+1);
	int pos=1;
	ans=0;
	while(pos<=n){
		pos=maxn[pos]+1;
		++ans;
	}
	printf("%d\n",ans);
}