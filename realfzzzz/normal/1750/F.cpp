// LUOGU_RID: 93159979
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
const int maxn=5e3+5;
int n;
ll p,f[maxn][maxn],s[maxn][maxn];
ll S(int x,int y){
	if(s[x][y]>=0) return s[x][y];
	s[x][y]=0;
	if((x+y)%2==0) s[x][y]=f[(x+y)/2][(x-y)/2];
	if(x) s[x][y]=(s[x][y]+S(x-1,y))%p;
	if(y) s[x][y]=(s[x][y]+S(x,y-1))%p;
	if(x&&y) s[x][y]=(s[x][y]-S(x-1,y-1)+p)%p;
	return s[x][y];
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	p=read();
	ll pw=1;
	memset(s,-1,sizeof(s));
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			f[i][j]=1;
			if(i>j*2) f[i][j]=(f[i][j]+S(i-j*2-1,i-j))%p;
			f[i][j]=f[i][j]*f[j][j]%p;
		}
		f[i][i]=pw;
		for(int j=0;j<i;j++) f[i][i]=(f[i][i]-f[i][j]+p)%p;
		pw=pw*2%p;
	}
	printf("%lld\n",f[n][n]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}