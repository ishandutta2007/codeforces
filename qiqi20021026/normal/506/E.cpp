#include<bits/stdc++.h>

using namespace std;

#define N 205
#define M 620

const int mod=10007;
int n,m,ans,f[N][N][N];
char s[N];

inline void upd(int &x,int y){x=(x+y)%mod;}

struct mat{
	int s[M][M];
	mat(){memset(s,0,sizeof s);}
	mat operator * (const mat &p) const{
		mat c;
		for (int k=1;k<n*3;++k)
			for (int i=1;i<n*3;++i) if (s[i][k])
				for (int j=1;j<n*3;++j) if (p.s[k][j])
					upd(c.s[i][j],s[i][k]*p.s[k][j]);
		return c;
	}
}g,h,hh;

inline mat pw(mat x,int k){
	mat r;
	for (int i=1;i<n*3;++i) r.s[i][i]=1;
	for (;k;k>>=1){if (k&1) r=r*x; x=x*x;}
	return r;
}

int main(){
	scanf("%s%d",s+1,&m); n=strlen(s+1); m+=n;
	for (int i=1;i<=n;++i) f[i][i][0]=1;
	for (int i=1;i<n;++i) if (s[i]==s[i+1]) f[i][i+1][0]=1;
	for (int i=0;i<n;++i)
		for (int j=1;j+i<=n;++j)
			for (int k=0,t;k<=n;++k) if (t=f[j][j+i][k]){
				if (j+i+1<=n&&s[j]!=s[j+i+1]) upd(f[j][j+i+1][k+1],t);
				if (j-1&&s[j-1]!=s[j+i]) upd(f[j-1][j+i][k+1],t);
				if (j-1&&j+i+1<=n&&s[j-1]==s[j+i+1]) upd(f[j-1][j+i+1][k],t);
			}
	for (int i=1;i<n;++i){g.s[i][i]=24; g.s[i][i+1]=1;}
	for (int i=n;i<n*2;++i){g.s[i][i]=25; if (i+1<n*2) g.s[i][i+1]=1; g.s[i][i+n]=1;}
	for (int i=n*2;i<n*3;++i) g.s[i][i]=26;
	h=pw(g,(m+1)/2-1); g=g*h;
	for (int i=0;i<=n;++i){
		int j=(n-i+1)/2-1;
		upd(ans,f[1][n][i]*g.s[n-i][n*2+j]);
		if ((m&1)&&!((n-i)&1)) upd(ans,(-f[1][n][i]*h.s[n-i][n+j])%mod+mod);
	}
	printf("%d\n",ans);
	
	return 0;
}