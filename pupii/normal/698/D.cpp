#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct vector{ll x,y;}A[1010],B[1010];
vector operator-(vector a,vector b){return{a.x-b.x,a.y-b.y};}
ll operator^(vector a,vector b){return a.x*b.y-a.y*b.x;}
ll operator*(vector a,vector b){return a.x*b.x+a.y*b.y;}
std::vector<int>s[8][1010];
int n,m,p[10],tm,now,vis[1010];
bool dfs(int x){
	int o=p[++now];if(now>m)return 0;
	for(int i:s[o][x])if(vis[i]<tm&&!dfs(i))return 0;
	return vis[x]=tm,1;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	m=gi(),n=gi();
	for(int i=1;i<=m;++i)A[i].x=gi(),A[i].y=gi();
	for(int i=1;i<=n;++i)B[i].x=gi(),B[i].y=gi();
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k){
				if(j==k)continue;
				vector J=B[j]-A[i],K=B[k]-A[i];
				if(!(J^K)&&(J*(J-K)>0)&&(J*K>0))s[i][j].push_back(k);
			}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)p[j]=j;
		do{
			++tm;now=0;
			if(dfs(i)){++ans;break;}
		}while(std::next_permutation(p+1,p+m+1));
	}
	printf("%d\n",ans);
	return 0;
}