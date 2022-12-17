#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
int n,m,eu[maxn*2],ev[maxn*2],ew[maxn*2];
set<int> g[3][maxn];
int m2,ch[maxn*2][2],ans[maxn*2];
void check(int u,int c){
	while((int)g[c][u].size()>1){
		int e1=*g[c][u].begin(),v1=eu[e1]==u?ev[e1]:eu[e1];
		g[c][u].erase(e1);
		g[c][v1].erase(e1);
		int e2=*g[c][u].begin(),v2=eu[e2]==u?ev[e2]:eu[e2];
		g[c][u].erase(e2);
		g[c][v2].erase(e2);
		if(v1==v2){
			ans[e1]=eu[e1]==u?1:2;
			ans[e2]=eu[e2]==u?2:1;
			return;
		}
		m2++;
		eu[m2]=v1;
		ev[m2]=v2;
		ew[m2]=c;
		g[c][v1].insert(m2);
		g[c][v2].insert(m2);
		ch[m2][0]=e1;
		ch[m2][1]=e2;
		check(v1,c);
		check(v2,c);
	}
}
int s[maxn];
bool vis[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=1;i<=m;i++){
		eu[i]=readint();
		ev[i]=readint();
		ew[i]=readint();
		g[ew[i]][eu[i]].insert(i);
		g[ew[i]][ev[i]].insert(i);
	}
	m2=m;
	for(int i=1;i<=n;i++){
		check(i,1);
		check(i,2);
	}
	for(int i=1;i<=n;i++) if(!vis[i]&&(!g[1][i].size()||!g[2][i].size())){
		int u=i,c=g[1][i].size()?1:2;
		while(g[c][u].size()){
			vis[u]=1;
			int e=*g[c][u].begin();
			ans[e]=eu[e]==u?1:2;
			s[u]+=ew[e];
			u=eu[e]==u?ev[e]:eu[e];
			s[u]-=ew[e];
			c^=3;
		}
		vis[u]=1;
	}
	for(int i=1;i<=n;i++) if(!vis[i]){
		int u=i,c=1;
		do{
			vis[u]=1;
			int e=*g[c][u].begin();
			ans[e]=eu[e]==u?1:2;
			s[u]+=ew[e];
			u=eu[e]==u?ev[e]:eu[e];
			s[u]-=ew[e];
			c^=3;
		}while(u!=i);
	}
	for(int i=m2;i>0;i--) if(ch[i][0]){
		ans[ch[i][0]]=eu[ch[i][0]]==eu[i]?ans[i]:(ans[i]^3);
		ans[ch[i][1]]=ev[ch[i][1]]==ev[i]?ans[i]:(ans[i]^3);
	}
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=abs(s[i])==1;
	printf("%d\n",cnt);
	for(int i=1;i<=m;i++) printf("%d",ans[i]);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}