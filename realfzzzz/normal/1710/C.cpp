#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n;
char s[maxn];
const ll mod=998244353;
inline void add(ll& x,ll y){
	x=(x+y)%mod;
}
ll f[2][8][8];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	f[0][7][0]=1;
	for(int i=1;i<=n;i++){
		bool d=i%2;
		memset(f[d],0,sizeof(f[d]));
		for(int j=0;j<8;j++) for(int k=0;k<8;k++)
			for(int x=0;x<8;x++){
				int j2,k2;
				if(s[i]=='1') j2=j&x;
				else if(!(j&x)) j2=j;
				else continue;
				if(x==1||x==6) k2=k|1;
				else if(x==2||x==5) k2=k|2;
				else if(x==4||x==3) k2=k|4;
				else k2=k;
				add(f[d][j2][k2],f[!d][j][k]);
			}
	}
	ll ans=0;
	for(int i=0;i<8;i++) add(ans,f[n%2][i][7]);
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}