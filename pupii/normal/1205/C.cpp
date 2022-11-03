#include<bits/stdc++.h>
#define il inline
#define vd void
#define flush fflush(stdout)
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
il bool query(int x1,int y1,int x2,int y2){
	printf("? %d %d %d %d\n",x1,y1,x2,y2);flush;
	return gi();
}
bool map[51][51];
bool f[51][51][51][51],g[51][51][51][51];
int main(){
	int n=gi();
	map[1][1]=map[1][2]=1;
	for(int i=3;i<=n;++i)map[1][i]=map[1][i-2]^1^query(1,i-2,1,i);
	for(int i=2;i<=n;++i)map[2][i]=map[1][i-1]^1^query(1,i-1,2,i);
	map[2][1]=map[2][3]^1^query(2,1,2,3);
	for(int i=3;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=n||j!=n)map[i][j]=map[i-2][j]^1^query(i-2,j,i,j);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			f[i][j][i][j]=g[i][j][i][j]=1;
			if(i<n&&map[i][j]==map[i+1][j])f[i][j][i+1][j]=1;else g[i][j][i+1][j]=1;
			if(j<n&&map[i][j]==map[i][j+1])f[i][j][i][j+1]=1;else g[i][j][i][j+1]=1;
		}
	for(int len=2;len<=n*2;++len)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				for(int k=std::max(i,i+j+len-n),l;k<=n&&k-i<=len;++k){
					l=j+len-(k-i);
					bool A=map[i][j],B=map[k][l];
					if(A==B){
						if(i<n&&k>1)f[i][j][k][l]|=f[i+1][j][k-1][l];
						if(j<n&&k>1)f[i][j][k][l]|=f[i][j+1][k-1][l];
						if(i<n&&l>1)f[i][j][k][l]|=f[i+1][j][k][l-1];
						if(j<n&&l>1)f[i][j][k][l]|=f[i][j+1][k][l-1];
					}
					A^=i+j&1,B^=k+l&1;
					if(A==B){
						if(i<n&&k>1)g[i][j][k][l]|=g[i+1][j][k-1][l];
						if(j<n&&k>1)g[i][j][k][l]|=g[i][j+1][k-1][l];
						if(i<n&&l>1)g[i][j][k][l]|=g[i+1][j][k][l-1];
						if(j<n&&l>1)g[i][j][k][l]|=g[i][j+1][k][l-1];
					}
				}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=i;k<=n;++k)
				for(int l=j;l<=n;++l)
					if(k+l-i-j>=2&&f[i][j][k][l]!=g[i][j][k][l]){
						if(query(i,j,k,l)==g[i][j][k][l])
							for(int i=1;i<=n;++i)
								for(int j=1;j<=n;++j)
									if(i+j&1)map[i][j]^=1;
						puts("!");
						for(int i=1;i<=n;++i){
							for(int j=1;j<=n;++j)printf("%c",map[i][j]+'0');
							puts("");
						}
						return flush,0;
					}
	assert(0);
}