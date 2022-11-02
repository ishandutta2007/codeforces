#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();
	int s=0;
	int x=1;
	while(c<'0' or c>'9')
	{
	if(c=='-')x=-1;
	c=getchar();
	}
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();
	return s*x;
} 
const int N=1505;
int T,n,m;
int c[N*N],top;
int f[N*N],pd[N];
inline int find(int z){
	if(f[z]!=z)return f[z]=find(f[z]);
	else return z;
}
vector<int>x,y;
int fa[N];
int vis[505][505];
struct node{
	int x,y,val;
}a[N*N];int ha;
int d[N][N];
int cmp(node x,node y){
	return x.val<y.val;
}
int main()
{
	n=read();
	int gg=0;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			a[++gg].x=i;a[gg].y=k;a[gg].val=read();
			d[i][k]=a[gg].val;
		}
	}
	for(int i=1;i<=n*n;i++)f[i]=i;
	top=n;
	sort(a+1,a+n*n+1,cmp);
	for(int i=1;i<=n*n;i++){
		int minn=a[i].val;
		if(vis[a[i].x][a[i].y])continue;
		int jlx=a[i].x,jly=a[i].y;
		if(jlx==jly){
			vis[jlx][jly]=1;
			c[jlx]=minn;
		}
		else{
			int g=++top;
			c[g]=minn;
			bool flag=0;
			for(int i=1;i<=n;i++){
				if(d[jlx][i]==minn){
					vis[jlx][i]=vis[i][jlx]=1;
					int gg=find(jlx);
					int h=find(i);
					if(gg==h)continue;
					flag=1;
					f[gg]=f[h]=g;
					fa[gg]=fa[h]=g;
				}
			}
			if(!flag)top--;
		}
	}
	printf("%d\n",top);
	for(int i=1;i<=top;i++){
		printf("%d ",c[i]);
	}
	puts("");
	printf("%d\n",find(1));
	for(int i=1;i<=top;i++){
		if(i!=find(1)){
			printf("%d %d\n",i,fa[i]);
		}
	}
	return 0;
}