#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
int min_4(int a,int b,int c,int d){
	return min(min(a,b),min(c,d));
}
const int Maxn=2000;
typedef long long ll;
int n,m;
char mp[Maxn+5][Maxn+5];
int f[Maxn+5][Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	ll ans=0;
	for(int i=3;i<=n;i++){
		for(int j=2;j<m;j++){
			if(mp[i-2][j]==mp[i][j]&&mp[i-1][j-1]==mp[i][j]&&mp[i-1][j]==mp[i][j]&&mp[i-1][j+1]==mp[i][j]){
				f[i][j]=min_4(f[i-2][j],f[i-1][j-1],f[i-1][j],f[i-1][j+1])+1;
				ans+=f[i][j];
			}
		}
	}
	printf("%lld\n",ans+n*m);
	return 0;
}