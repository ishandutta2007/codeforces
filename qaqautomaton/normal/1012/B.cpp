/*
Author: CNYALI_LK
LANG: C++
PROG: B.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<int,int> pii;
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
int read(){
	int s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
int fa[404847];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
#ifdef cnyali_lk
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	int n,m,q,x,y;
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n+m;++i)fa[i]=i;
	int ans=n+m-1;
	for(;q;--q){
		x=read();y=read()+n;
		if(find(x)!=find(y)){
			--ans;
			fa[find(x)]=find(y);
		}
	}
	printf("%d\n",ans);
	return 0;
}