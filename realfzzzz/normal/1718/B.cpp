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
const int maxn=100+5;
int n,a[maxn],f[45];
ll calc(int x){
	ll s=0;
	for(int i=44;i>0;i--) if(x>=f[i]){
		s|=1ll<<i;
		x-=f[i];
	}
	return s;
}
int s1[maxn][45],s2[maxn][45];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	f[0]=f[1]=1;
	for(int i=2;i<45;i++) f[i]=f[i-1]+f[i-2];
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++){
			ll x=calc(a[i]);
			for(int j=1;j<45;j++) s1[i][j]=s1[i-1][j]+(x>>j&1);
		}
		memset(s2[n+1],0,sizeof(s2[0]));
		for(int i=n;i>0;i--){
			ll x=calc(a[i]);
			for(int j=1;j<45;j++) s2[i][j]=s2[i+1][j]+(x>>j&1);
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			ll x=calc(a[i]-1);
			if(x>>1&1) continue;
			int flag2=0;
			for(int j=1;j<45;j++){
				int s=s1[i-1][j]+(x>>j&1)+s2[i+1][j];
				if(!s&&flag2==0) flag2=1;
				if(s>1||(s==1&&flag2==1)) flag2=2;
			}
			flag|=flag2==1;
		}
		printf(flag?"YES\n":"NO\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}