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
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char*)&inf,(unsigned char*)&inf+sizeof(inf),0x3f);
	}
}__INIT___;
int a[105];
int n;
int ask(vector<int> vt){
	cout<<'?';
	for(auto i:vt)cout<<' '<<i;
	cout<<endl;
	int x;
	cin>>x;
	return x;
}
void chk(int x){
	if(x>0){
		cout<<'?';
		for(int i=1;i<n;++i)cout<<' '<<n-x;
		cout<<' '<<n<<endl;
	}
	else{
		cout<<'?';
		for(int i=1;i<n;++i)cout<<' '<<n;
		cout<<' '<<n+x<<endl;
	}
	int w;
	cin>>w;
	if(w)a[w]=x;
}
signed main(){
	cin>>n;
	for(int i=-n+1;i<n;++i)if(i){
		chk(i);
	}
	int s=1;
	for(int i=1;i<n;++i)if(a[i]<0)++s;
	for(int i=1;i<=n;++i)a[i]+=s;
	cout<<'!';
	for(int i=1;i<=n;++i)cout<<' '<<a[i];
	cout<<endl;
	return 0;
}