/*
Author: QAQAutoMaton
Lang: C++
Code: D.cpp
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
int n,d[2005];
void ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	for(int i=1;i<=n;++i)scanf("%d",d+i);
}
vector<pii> ans;
void xask(int x){
	ask(x);
	for(int i=1;i<=n;++i)if(d[i]==1){
		ans.emplace_back(x,i);
	}
}
vector<int> v[2];
signed main(){
	scanf("%d",&n);
	ask(1);
	for(int i=2;i<=n;++i)v[d[i]&1].emplace_back(i);
	if(v[0].size()<v[1].size()){
		for(int i=1;i<=n;++i)if(d[i]==1)ans.emplace_back(1,i);
		for(auto i:v[0])xask(i);
	}
	else{
		for(auto i:v[1])xask(i);
	}
	printf("!\n");
	for(auto i:ans)printf("%d %d\n",i.x,i.y);
	fflush(stdout);

	return 0;
}