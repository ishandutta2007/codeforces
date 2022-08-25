/*
Author: QAQAutomaton
Lang: C++
Code: F.cpp
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
bitset<1005> ok,now;
vector<int> put;
void end(){cout<<0<<endl;exit(0);}
int n;
void output(){
	cout<<put.size()<<endl;
	for(auto i:put)cout<<i<<' ';
	cout<<endl;
	int w;
	cin>>w;
	for(int i=1;i<=put.size();++i){
		now[w]=0;
		if(w==n)w=1;else ++w;
	}
}
signed main(){
	cin>>n;
	int cur=1,ans=0;
	for(int i=2;i<=n;++i){
		if(chkmax(ans,n-((n-1)/i+1)-(i-1)))cur=i;
	}
	if(!ans)end();
	for(int i=1;i<=n;++i){
		ok[i]=!!((i-1)%cur);
	}
	while(1){
		int c=cur,ed=0;
		put.clear();
		for(int i=1;i<=n;++i){
			if(ok[i] && !now[i]){
				if(!c){ed=0;break;}
				now[i]=1;
				put.emplace_back(i);
				--c;
				if(!c)ed=1;
			}
		}
		output();
		if(ed)end();
	}
	return 0;
}