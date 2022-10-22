#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
const int N=200005;
int n,K,len[N],son[N],w[N];
vector<int>e[N];
void dfs1(int k1,int k2){
	for(auto&x:e[k1])if(x!=k2){
		dfs1(x,k1);
		if(len[son[k1]]<len[x]){
			son[k1]=x;
		}
	}
	len[k1]=len[son[k1]]+1;
}
vector<int>v;
void dfs2(int k1,int k2){
	v.pb(len[k1]);
	while(1){
		for(auto&x:e[k1])if(x!=k2&&x!=son[k1]){
			dfs2(x,k1);
		}
		if(son[k1]){
			k2=k1;
			k1=son[k1];
		}else{
			break;
		}
	}
}
int main(){
	scanf("%d%d",&n,&K);
	rep(i,2,n){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	sort(v.begin(),v.end(),greater<void>());
	rep(i,1,K){
		if(i-1<SZ(v)){
			w[i]=w[i-1]+v[i-1]-1;
		}else{
			w[i]=w[i-1]-1;
		}
	}
	LL ans=~INFLL;
	rep(i,0,K){
		if(i-(n-i-w[i])>=0){
			ans=max(ans,1LL*w[i]*(i-(n-i-w[i])));
		}
	}
	if(ans<0){
		auto sol=[&](int a,int b,int c){ // 0<=x<=a min((b-x)*(c-x))
			a-=c,b-=c; // 0<=x<=a min((b-x)*(-x))
			auto f=[&](int x){
				if(0<=x&&x<=a)return 1LL*(b-x)*(-x);
				else return INFLL;
			};
			int x1=b/2;
			int x2=(b+1)/2;
			return min({f(0),f(a),f(x1),f(x2)});
		};
		rep(i,0,K){
			ans=max(ans,sol(n-i-w[i],n-i,i));
		}
	}
	printf("%lld\n",ans);
	return 0;
}