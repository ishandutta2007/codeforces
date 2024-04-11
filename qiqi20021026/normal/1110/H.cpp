#include<bits/stdc++.h>

using namespace std;

#define N 1000
#define M (N*16)

int n,a[N],b[N],s[N],aa,bb,cnt,fa[M],f[2005][M],F[2005][M],g[M][2005],c[M][10],q[M];
char s1[N],s2[N];

void dfs(int x,int fl,int fr){
	if ((!fl&&!fr)||!x){
		int i;
		for (i=bb;i>1&&s[i]==0;--i);
		int t=1;
		for (;i>x;--i){
			if (!c[t][s[i]]) c[t][s[i]]=++cnt;
			t=c[t][s[i]];
		}
		++g[t][x];
		return;
	}
	for (int i=0;i<=9;++i){
		if (fl&&i<a[x]) continue;
		if (fr&&i>b[x]) continue;
		s[x]=i;
		dfs(x-1,fl&(i==a[x]),fr&(i==b[x]));
	}
}

int main(){
	scanf("%s%s",s1+1,s2+1);
	scanf("%d",&n);
	aa=strlen(s1+1); for (int i=1;i<=aa;++i) a[i]=s1[i]-'0';
	bb=strlen(s2+1); for (int i=1;i<=bb;++i) b[i]=s2[i]-'0';
	reverse(a+1,a+aa+1); reverse(b+1,b+bb+1);
	cnt=1; dfs(bb,1,1);
	int tt=0,ww=1; q[1]=1;
	while (tt<ww){
		int u=q[++tt];
		for (int i=0;i<=9;++i)
			if (c[u][i]){
				int t=fa[u];
				for (;t&&!c[t][i];t=fa[t]);
				fa[c[u][i]]=t?c[t][i]:1;
				q[++ww]=c[u][i];
			}
			else c[u][i]=fa[u]?c[fa[u]][i]:1;
	}
	for (int i=1;i<=cnt;++i)
		for (int j=1;j<=n;++j) g[i][j]+=g[i][j-1];
	for (int i=1;i<=cnt;++i)
		for (int j=0;j<=n;++j) g[q[i]][j]+=g[fa[q[i]]][j];
	for (int i=1;i<=n;++i){
		for (int j=1;j<=cnt;++j){
			f[i][j]=-1;
			for (int k=0;k<=9;++k){
				int t=c[j][k];
				if (f[i-1][t]+g[t][i-1]>f[i][j]){
					f[i][j]=f[i-1][t]+g[t][i-1];
					F[i][j]=k;
				}
			}
		}
	}
	printf("%d\n",f[n][1]);
	for (int i=n,x=1;i;--i){
		printf("%d",F[i][x]);
		x=c[x][F[i][x]];
	}
	puts("");
	
	return 0;
}