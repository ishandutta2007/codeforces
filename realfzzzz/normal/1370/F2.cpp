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
const int maxn=1e3+5;
int n;
vector<int> g[maxn];
void dfs(int u,int fa,int k,vector<int>& res){
	if(!k){
		res.push_back(u);
		return;
	}
	for(int v:g[u]) if(v!=fa) dfs(v,u,k-1,res);
}
int main(){
	#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) vector<int>().swap(g[i]);
		for(int i=1;i<n;i++){
			int u,v;
			u=readint();
			v=readint();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		printf("? %d ",n);
		for(int i=1;i<=n;i++) printf("%d ",i);
		printf("\n");
		fflush(stdout);
		int x,d;
		x=readint();
		d=readint();
		int l=(d+1)/2,r=d,ans=-1;
		while(l<=r){
			int mid=l+(r-l)/2;
			vector<int> vec;
			dfs(x,0,mid,vec);
			if(!vec.size()){
				r=mid-1;
				continue;
			}
			printf("? %d ",(int)vec.size());
			for(int i:vec) printf("%d ",i);
			printf("\n");
			fflush(stdout);
			int res=readint();
			if(readint()==d){
				l=mid+1;
				ans=res;
			}
			else r=mid-1;
		}
		vector<int> vec;
		dfs(ans,0,d,vec);
		printf("? %d ",(int)vec.size());
		for(int i:vec) printf("%d ",i);
		printf("\n");
		fflush(stdout);
		printf("! %d %d\n",ans,readint());
		fflush(stdout);
		readint();
	}
	return 0;
}