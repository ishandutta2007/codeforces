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
int n,m,s[maxn][maxn][maxn],f[maxn][maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int l,r;
			l=read();
			r=read();
			for(int j=l;j<=r;j++) s[j][l][r]++;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=2;k<=m;k++) s[i][j][k]+=s[i][j][k-1];
	for(int i=1;i<=m;i++)
		for(int j=m-1;j>0;j--)
			for(int k=1;k<=m;k++) s[i][j][k]+=s[i][j+1][k];
	for(int i=m;i>0;i--) for(int j=i;j<=m;j++) for(int k=i;k<=j;k++)
		f[i][j]=max(f[i][j],f[i][k-1]+f[k+1][j]+s[k][i][j]*s[k][i][j]);
	printf("%d\n",f[1][m]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}