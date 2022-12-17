#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,m;
vector<pair<int,int>> g1[maxn],g2[maxn];
int cnt1=0,no1[maxn],s1[maxn];
void dfs1(int u){
	s1[no1[u]=cnt1]+=u<=n;
	for(auto e:g1[u]){
		int v=e.second;
		if(!no1[v]) dfs1(v);
	}
}
int cnt2=0,no2[maxn],s2[maxn];
void dfs2(int u){
	s2[no2[u]=cnt2]+=u<=n;
	for(auto e:g2[u]){
		int v=e.second;
		if(!no2[v]) dfs2(v);
	}
}
int p[maxn];
bool vis[maxn];
vector<int> vec;
bool dfs3(int u){
	vec.push_back(u);
	vis[p[u]]=1;
	if(g1[u].size()!=g2[p[u]].size()) return 0;
	for(int i=0;i<(int)g1[u].size();i++){
		auto e1=g1[u][i],e2=g2[p[u]][i];
		int v1=e1.second,v2=e2.second;
		if(e1.first!=e2.first) return 0;
		if(p[v1]||vis[v2]){
			if(p[v1]!=v2) return 0;
			continue;
		}
		p[v1]=v2;
		if(!dfs3(v1)) return 0;
	}
	return 1;
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	bool flag=n>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		int a=read();
		if(!a) continue;
		if(flag){
			g1[j].push_back({a,m+i});
			g1[m+i].push_back({a,j});
		}
		else{
			g1[i].push_back({a,n+j});
			g1[n+j].push_back({a,i});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		int b=read();
		if(!b) continue;
		if(flag){
			g2[j].push_back({b,m+i});
			g2[m+i].push_back({b,j});
		}
		else{
			g2[i].push_back({b,n+j});
			g2[n+j].push_back({b,i});
		}
	}
	if(flag) swap(n,m);
	for(int i=1;i<=n+m;i++)
		sort(g1[i].begin(),g1[i].end());
	for(int i=1;i<=n+m;i++)
		sort(g2[i].begin(),g2[i].end());
	for(int i=1;i<=n+m;i++) if(!no1[i]){
		cnt1++;
		dfs1(i);
	}
	for(int i=1;i<=n+m;i++) if(!no2[i]){
		cnt2++;
		dfs2(i);
	}
	for(int i=1;i<=n;i++) if(!p[i]){
		for(int j=1;j<=n;j++)
			if(!vis[j]&&s1[no1[i]]==s2[no2[j]]){
				p[i]=j;
				vec.clear();
				if(dfs3(i)) break;
				for(int k:vec){
					vis[p[k]]=0;
					p[k]=0;
				}
			}
		if(!p[i]){
			printf("-1\n");
			return 0;
		}
	}
	vector<int> vec;
	for(int i=n+1;i<=n+m;i++)
		if(!vis[i]) vec.push_back(i);
	for(int i=n+1;i<=n+m;i++) if(!p[i]){
		p[i]=vec.back();
		vec.pop_back();
	}
	vector<pair<int,int>> ans1,ans2;
	for(int i=1;i<=n;i++) while(p[i]!=i){
		ans1.push_back({i,p[i]});
		swap(p[i],p[p[i]]);
	}
	for(int i=1;i<=m;i++) while(p[n+i]!=n+i){
		ans2.push_back({i,p[n+i]-n});
		swap(p[n+i],p[p[n+i]]);
	}
	printf("%d\n",(int)(ans1.size()+ans2.size()));
	for(auto x:ans1)
		printf("%d %d %d\n",flag?2:1,x.first,x.second);
	for(auto x:ans2)
		printf("%d %d %d\n",flag?1:2,x.first,x.second);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}