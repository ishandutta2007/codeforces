#include<vector>
#include<cstring>
#include<cctype>
#include<cstdio>
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
const int maxn=2e5+5;
int n,k;
vector<int> g[maxn];
int fa[maxn],dep[maxn],size[maxn];
void dfs(int u){
	dep[u]=dep[fa[u]]+1;
	size[u]=1;
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i];
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs(v);
		size[u]+=size[v];
	}
}
double l,r,mid;
bool c[maxn];
double dp(int u){
	double res=0;
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i];
		if(v==fa[u]) continue;
		res+=dp(v);
	}
	if(res<size[u]*(dep[u]-1+mid)){
		c[u]=1;
		return size[u]*(dep[u]-1+mid);
	}
	else{
		c[u]=0;
		return res;
	}
}
int count(int u){
	if(c[u]) return size[u];
	int cnt=0;
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i];
		if(v==fa[u]) continue;
		cnt+=count(v);
	}
	return cnt;
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    k=readint();
    for(int i=1;i<n;i++){
    	int u,v;
    	u=readint();
    	v=readint();
    	g[u].push_back(v);
    	g[v].push_back(u);
	}
	dfs(1);
	l=-n;
	r=n;
	while(r-l>1e-5){
		mid=l+(r-l)/2;
		memset(c,0,sizeof(c));
		dp(1);
		if(count(1)<k) l=mid;
		else r=mid;
	}
	r=mid;
	printf("%.f\n",dp(1)-r*k);
    return 0;
}