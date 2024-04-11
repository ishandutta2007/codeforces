#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=1005;
int n;
set<int> G[Maxn];
int ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int v;
	scanf("%d",&v);
	return v;
}
set<int> rem;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) rem.insert(i);
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);G[u].insert(v);G[v].insert(u);
	}
	int R=n;
	while (R>1){
		vector<int> V;
		for (int i=1;i<=n;i++){
			if (G[i].size()==1){
				V.pb(i);
			}
		}
		int u=V[0],v=V[1];
		int h=ask(u,v);
		if (h==u){
			printf("! %d\n",u);
			fflush(stdout);
			return 0;
		}
		if (h==v){
			printf("! %d\n",v);
			fflush(stdout);
			return 0;
		}
		int pu=*G[u].begin();
		G[u].erase(pu);G[pu].erase(u);
		int pv=*G[v].begin();
		G[v].erase(pv);G[pv].erase(v);
		R-=2;
		rem.erase(u);rem.erase(v);
	}
	if (R==1){
				printf("! %d\n",*rem.begin());
				fflush(stdout);
				return 0;
	}
}