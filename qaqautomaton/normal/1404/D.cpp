/*
Author: QAQAutomaton
Lang: C++
Code: D.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cp;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T,class T2>int chkmin(T &a,T2 b){return a>b?a=b,1:0;}
template<class T,class T2>int chkmax(T &a,T2 b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		memset(&inf,0x3f,sizeof(inf));
	}
}__INIT___;
int a[1000005];
vector<int> to[1000005],hv[500005];
bitset<1000005>vis,col;
int n,s,o;
void dfs(int x,int c){
	vis[x]=1;col[x]=c;
	if(c){++s;}
	for(auto i:to[x])if(!vis[i])dfs(i,c^1);
}
signed main(){
	scanf("%d",&n);
	if(!(n&1)){
		printf("First\n");
		for(int i=1;i<=n+n;++i){
			printf("%d\n",i>n?i-n:i);
		}
	}
	else{
		printf("Second\n");
		fflush(stdout);
		for(int i=1;i<=n+n;++i){
			scanf("%d",a+i);
			hv[a[i]].emplace_back(i);
		}
		for(int i=1;i<=n;++i){
			to[i].emplace_back(i+n);
			to[i+n].emplace_back(i);
			to[hv[i][0]].emplace_back(hv[i][1]);
			to[hv[i][1]].emplace_back(hv[i][0]);
		}
		for(int i=1;i<=n+n;++i)if(!vis[i]){
			s=0;
			dfs(i,0);
			if(s&1)o=i;
		}
		int cnt=0;
		for(int i=1;i<=n+n;++i)if(col[i])(cnt+=i)>=n+n?cnt-=n+n:0;
		assert(cnt==0||cnt==n);
		if(cnt==n){
			vis.reset();
			dfs(o,1);
		}
		for(int i=1;i<=n;++i)if(col[hv[i][0]])printf("%d%c",hv[i][0],i==n?'\n':' ');
		else printf("%d%c",hv[i][1],i==n?'\n':' ');
	}
	fflush(stdout);
	return 0;
}