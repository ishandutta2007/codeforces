#include<map>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=50,maxm=1000,mod=1000000007;
map<ll,int> mp;
int n,m; char s[maxn+10][maxm+10];
ll f[maxm+10][maxm+10],ans=1;
ll work(int v){
	for(int i=0;i<=v;++i) for(int j=0;j<=v;++j) f[i][j]=0;
	f[0][0]=1; ll ans=0;
	for(int i=0;i<v;++i)
		for(int j=0;j<v;++j){
			(f[i+1][j+1]+=f[i][j])%=mod;
			(f[i][j+1]+=f[i][j]*i%mod)%=mod;
		}
	for(int i=0;i<=v;++i) (ans+=f[i][v])%=mod;
	return ans;
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i) scanf("%s",s[i]);
	for(int i=0;i<m;++i){
		ll ans=0;
		for(int j=1;j<=n;++j) ans=ans*2+s[j][i]-'0';
		++mp[ans];
	}
	for(map<ll,int>::iterator it=mp.begin();it!=mp.end();++it) (ans*=work(it->second))%=mod;
	printf("%lld",ans);
}