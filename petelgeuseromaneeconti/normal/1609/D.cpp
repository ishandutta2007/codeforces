#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=1005;
int n,d,fa[N],sz[N];
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
int calc(int k){
	vector<int>v;
	rep(i,1,n){
		if(fd(i)==i)v.pb(sz[i]);
	}
	sort(v.begin(),v.end());
	int ans=0;
	while(k--&&!v.empty()){
		ans+=v.back();
		v.pop_back();
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&d);
	rep(i,1,n)fa[i]=i,sz[i]=1;
	int tot=1;
	rep(i,1,d){
		int u,v;
		scanf("%d%d",&u,&v);
		u=fd(u),v=fd(v);
		if(u==v){
			++tot;
			printf("%d\n",calc(tot)-1);
			continue;
		}
		fa[u]=v,sz[v]+=sz[u];
		printf("%d\n",calc(tot)-1);
	}
	return 0;
}