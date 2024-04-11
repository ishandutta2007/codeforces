/*
Author: QAQAutoMaton
Lang: C++
Code: E.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(qaq...) fprintf(stderr,qaq)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())
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
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char*)&inf,(unsigned char*)&inf+sizeof(inf),0x3f);
	}
}__INIT___;
int a[250005];
bool chk(int v,int k,int n){
	if(v*k<n)return 0;
	if((v*k-n)&1)return 0;
	int s=(v*k-n)>>1;
	return ((((v-1)>>1)<<1|1)*n>=v*k);
}
signed main(){
	int n,k;	
	scanf("%d%d",&n,&k);
	int v=(n-1)/k+1;
	while(v<=500 && !chk(v,k,n))++v;
	if(v>500){printf("-1\n");return 0;}
	int s=v*k+1;
	int l=(v-1)>>1<<1;
	for(int i=n;i;--i){
		--s;
		int las=max(s-l,i);
		for(int j=las;j<=s;++j)a[j]=i;
		s=las;
	}
	int ans=0;
	for(int i=1;i<=v;++i){
		printf("?");
		for(int j=0;j<k;++j){
			printf(" %d",a[j*v+i]);
		}
		printf("\n");
		fflush(stdout);
		int w;
		scanf("%d",&w);
		ans^=w;
	}
	printf("! %d\n",ans);
	return 0;
}