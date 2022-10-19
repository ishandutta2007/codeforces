#include<bits/stdc++.h>

using namespace std;

#define N 600

int n,m,cnt,tot,c[N][10],f[N][N][12],g[N][12],a[N];
char s[N];

void ins(int len,int x){
	int now=1;
	for (int i=1;i<=len;++i){
		if (!c[now][s[i]-'0']) c[now][s[i]-'0']=++cnt;
		now=c[now][s[i]-'0'];
	}
	a[now]+=x;
}

void upd(int &x,int y){
	x=max(x,y);
}

void dp(int x,int dep){
	for (int i=0;i<10;++i){
		int y=c[x][i];
		if (y){
			dp(y,dep+1);
			a[x]+=a[y];
			memset(g,0,sizeof g);
			for (int j=0;j<=dep;++j){
				for (int k=0;k<=m;++k){
					for (int l=0;k+l<=m;++l){
						upd(g[j][k+l],f[x][j][k]+f[y][j][l]);
					}
				}
			}
			memcpy(f[x],g,sizeof f[x]);
		}
	}
	for (int i=0;i<dep;++i){
		for (int j=0;j<m;++j){
			upd(f[x][i][j+1],f[x][dep][j]+a[x]*(dep-i));
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	cnt=1;
	for (int i=1;i<=n;++i){
		int x; scanf("%s%d",s+1,&x);
		tot+=strlen(s+1)*x;
		ins(strlen(s+1),x);
	}
	dp(1,0);
	printf("%d\n",tot-f[1][0][m]);
	
	return 0;
}