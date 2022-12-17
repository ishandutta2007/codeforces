#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ull readint(){
	ull x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e3+5;
int n;
char s[maxn],t[maxn];
bool check(char x,char y){
	return x==y||x=='?';
}
const ll mod=1e9+7;
inline void add(ll& x,ll y){
	x=(x+y)%mod;
}
ll f[2][maxn*2],g[2][maxn*2];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s%s",s+1,t+1);
		for(int i=1;i<=n;i+=2){
			if(s[i]!='?') s[i]=s[i]=='0'?'1':'0';
			if(t[i]!='?') t[i]=t[i]=='0'?'1':'0';
		}
		for(int i=-n-1;i<=n+1;i++)
			f[0][n+1+i]=g[0][n+1+i]=0;
		f[0][n+1]=1;
		for(int i=1;i<=n;i++){
			for(int j=-n-1;j<=n+1;j++)
				f[i%2][n+1+j]=g[i%2][n+1+j]=0;
			for(int j=-i;j<=i;j++){
				if(check(s[i],'0')&&check(t[i],'0')){
					add(f[i%2][n+1+j],f[(i-1)%2][n+1+j]);
					add(g[i%2][n+1+j],g[(i-1)%2][n+1+j]);
				}
				if(check(s[i],'0')&&check(t[i],'1')){
					add(f[i%2][n+1+j],f[(i-1)%2][n+2+j]);
					add(g[i%2][n+1+j],g[(i-1)%2][n+2+j]);
				}
				if(check(s[i],'1')&&check(t[i],'0')){
					add(f[i%2][n+1+j],f[(i-1)%2][n+j]);
					add(g[i%2][n+1+j],g[(i-1)%2][n+j]);
				}
				if(check(s[i],'1')&&check(t[i],'1')){
					add(f[i%2][n+1+j],f[(i-1)%2][n+1+j]);
					add(g[i%2][n+1+j],g[(i-1)%2][n+1+j]);
				}
				add(g[i%2][n+1+j],abs(j)*f[i%2][n+1+j]%mod);
			}
		}
		printf("%lld\n",g[n%2][n+1]);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}