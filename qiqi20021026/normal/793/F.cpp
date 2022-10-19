#include<bits/stdc++.h>

using namespace std;

#define N 120000
#define M 320
#define B(x) ((x)/M)

int l,n,m,x,y,ans,pre[N],go[N][320],mx[N][320],w[N],q[320][N];

int main(){
	scanf("%d%d",&l,&n);
	for (int i=1;i<=n;++i){scanf("%d%d",&x,&y); pre[y]=x;}
	for (int i=l;i>=1;--i){
		for (int j=B(i);j<=B(l);++j){
			mx[i][j]=max(mx[i][j],i);
			go[i][j]=max(go[i][j],i);
		}
		if (pre[i])
			for (int j=B(i);j<=B(l);++j)
				mx[pre[i]][j]=max(mx[pre[i]][j],i);
		for (int j=B(i);j<=B(l);++j){
			int x=mx[i][j];
			for (;w[j];--w[j]){
				if (q[j][w[j]]>x) break;
				go[i][j]=max(go[i][j],go[q[j][w[j]]][j]);
			}
			q[j][++w[j]]=i;
		}
	}
	scanf("%d",&m);
	for (int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		ans=x;
		for (int j=B(x);j<B(y);++j)
			ans=max(ans,go[x][j]);
		for (int j=B(y)*M;j<=y;++j)
			if (pre[j]>=x&&pre[j]<=ans) ans=max(ans,j);
		printf("%d\n",ans);
	}
	
	return 0;
}