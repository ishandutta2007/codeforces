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
const int maxn=3e5+5;
int n,m;
vector<int> g[maxn];
int c[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		m=readint();
		for(int i=1;i<=n;i++) vector<int>().swap(g[i]);
		for(int i=0;i<m;i++){
			int u,v;
			u=readint();
			v=readint();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++) c[i]=-1;
		queue<int> q;
		q.push(1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(c[u]>=0) continue;
			c[u]=1;
			for(int v:g[u]) if(c[v]<0){
				c[v]=0;
				for(int w:g[v]) if(u!=w) q.push(w);
			}
		}
		bool flag=1;
		for(int i=1;i<=n;i++) if(c[i]<0) flag=0;
		if(!flag){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		vector<int> ans;
		for(int i=1;i<=n;i++) if(c[i]==1) ans.push_back(i);
		printf("%d\n",(int)ans.size());
		for(int i:ans) printf("%d ",i);
		printf("\n");
	}
	return 0;
}