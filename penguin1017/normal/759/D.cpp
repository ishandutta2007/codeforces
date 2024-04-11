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
using namespace std;
const int N=5e3+9;
const ll mod=1e9+7;
char s[N];
ll tot[26][N],jie[N],inv[N];
bool vis[30];
void pre(){
	jie[0]=jie[1]=1;
	inv[0]=inv[1]=1;
	rep(i,2,N){
		int k=mod/i,r=mod%i;
		inv[i]=-k*inv[r]%mod;
		inv[i]+=mod;
	}
	rep(i,1,N)jie[i]=jie[i-1]*i%mod,inv[i]=inv[i]*inv[i-1]%mod;
}
int main(){
	pre();
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n+1){
		per(j,1,i){
			ll sum=0;
			rep(k,0,26){
				if(s[i]-'a'==k)continue;
				sum+=tot[k][j];
			}
			//cout<<sum<<' '<<j<<"check\n";
			tot[s[i]-'a'][j+1]=sum%mod;
		}
		tot[s[i]-'a'][1]=1;
	}
	ll ans=0;
	rep(i,1,n+1){
		ll sum=0;
		rep(j,0,26)sum+=tot[j][i];
		//cout<<sum<<"sum\n";
		sum%=mod;
		ans+=sum*jie[n-1]%mod*inv[i-1]%mod*inv[n-i]%mod;
	}
	ans%=mod;
	cout<<ans;
}