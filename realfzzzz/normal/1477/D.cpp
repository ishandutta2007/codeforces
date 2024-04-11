#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=5e5+5;
int n,m,p[maxn],q[maxn];
set<int> g[maxn];
vector<int> g2[maxn];
set<int> s[maxn];
int f[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		m=readint();
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=0;i<m;i++){
			int l,r;
			l=readint();
			r=readint();
			g[l].insert(r);
			g[r].insert(l);
		}
		set<int> q1;
		for(int i=1;i<=n;i++) q1.insert(i);
		for(int i=1;i<=n;i++) g2[i].clear();
		while(q1.size()){
			queue<int> q2;
			q2.push(*q1.begin());
			q1.erase(q1.begin());
			while(q2.size()){
				int u=q2.front();
				q2.pop();
				vector<int> res;
				for(int v:q1) if(g[u].find(v)==g[u].end()){
					g2[u].push_back(v);
					g2[v].push_back(u);
					res.push_back(v);
					q2.push(v);
				}
				for(int v:res) q1.erase(v);
			}
		}
		for(int i=1;i<=n;i++){
			f[i]=0;
			s[i].clear();
		}
		for(int i=1;i<=n;i++) if(g2[i].size()&&!s[i].size()&&!f[i]){
			bool flag=0;
			for(int j:g2[i]) if(!s[j].size()&&!f[j]) flag=1;
			if(flag){
				for(int j:g2[i]) if(!s[j].size()&&!f[j]){
					s[i].insert(j);
					f[j]=i;
				}
			}
			else{
				int v=g2[i][0];
				if(!f[v]){
					s[v].insert(i);
					f[i]=v;
				}
				else if((int)s[f[v]].size()>1){
					s[f[v]].erase(v);
					s[i].insert(v);
					f[v]=i;
				}
				else{
					s[f[v]].clear();
					f[f[v]]=v;
					f[i]=v;
					s[v].insert(i);
					s[v].insert(f[v]);
					f[v]=0;
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(!g2[i].size()) p[i]=q[i]=++cnt;
			else if(s[i].size()){
				p[i]=cnt+1;
				q[i]=cnt+s[i].size()+1;
				cnt++;
				for(int j:s[i]){
					p[j]=cnt+1;
					q[j]=cnt;
					cnt++;
				}
			}
		for(int i=1;i<=n;i++) printf("%d ",p[i]);
		printf("\n");
		for(int i=1;i<=n;i++) printf("%d ",q[i]);
		printf("\n");
	}
	return 0;
}