#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,q;
char c[300005];
V<int> st;
int p[300005];
V<int> v[300005];
int dfn[300005],r[300005],cnt,pos[300005],ans[300005],siz[300005],fa[300005],pos2[300005],cnt2;
struct bit{
	int s[300005];
	void update(int x,int y){
		while(x<=n){
			s[x]+=y;
			x+=x&-x;
		}
	}
	int get(int x){
		int re=0;
		while(x){
			re+=s[x];
			x-=x&-x;
		}
		RE re;
	}
}T,T2;
void dfs(int x){
	dfn[x]=++cnt;
	int in=0;
	for(auto u:v[x]){
		pos[u]=++in;fa[u]=x;
		dfs(u);
	}
	for(auto u:v[x]){
		pos2[u]=++cnt2;
		T2.update(pos2[u],1);
	}
	ans[x]=in*(in+1)/2;
	siz[x]=in;
	r[x]=cnt;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	FOR(i,1,n)cin>>c[i];
	FOR(i,1,n){
		if(c[i]=='('){
			st.PB(i);
		}else{
			if(!st.empty()){
				p[i]=st.back();st.pop_back();
				if(!st.empty())v[st.back()].PB(p[i]);
				else v[0].PB(p[i]);
			}
		}
	}
	if(!st.empty())v[0].PB(st[0]);
	if(st.size()>1)rep(i,0,st.size()-1){
		v[st[i]].PB(st[i+1]);
	}
	dfs(0);
	FOR(i,1,n){
		ans[i]+=ans[i-1];
	}
	FOR(i,1,q){
		int tt,l,r;
		cin>>tt>>l>>r;
		if(tt==2){
			int t=T2.get(pos2[p[r]])-T2.get(pos2[l]-1);
			cout<<ans[r]-ans[l-1]+t*(t+1)/2+T.get(r)-T.get(l-1)<<'\n';
		}else{
			int s=siz[fa[l]];
			if(fa[l])T.update(fa[l],-s);
			siz[fa[l]]--;
			T2.update(pos2[l],-1);
		}
	}
	RE 0;
}