#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=(int)2e5+9;
int fa[N],fa2[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int find2(int x){
	if(fa2[x]==x)return x;
	return fa2[x]=find2(fa2[x]);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)fa[i]=i,fa2[i]=i;
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			if(fu>fv)swap(fu,fv);
			fa[fv]=fu;
		}
		fu=find2(u),fv=find2(v);
		if(fu!=fv){
			if(fu>fv)swap(fu,fv);
			fa2[fu]=fv;
		}
	}
	int ans=0,mini=1,maxn=find2(1);
	rep(i,1,n+1){
		int fi=find(i);
		if(fi>mini){
			if(fi<maxn){
				++ans;
				fa[fi]=mini;
				fi=find2(i);
				if(maxn<fi)fa2[maxn]=fi,maxn=fi;
				else fa2[fi]=maxn;
			}
			else{
				mini=i;
				maxn=find2(i);
			}
		}
	}
	printf("%d",ans);
}