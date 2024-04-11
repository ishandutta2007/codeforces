/*
Author: QAQAutoMaton
Lang: C++
Code: E.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
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
ll ans,cur;
int cnt;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int ask(int x){
/*	++cnt;
	if(x<=ans){cur+=x;return 1;}
	(cur-=x);
	assert(cur>=0);
	return 0;*/
	cout<<"? "<<x<<endl;
	string res;
	cin>>res;
	if(res[0]=='L')return 1;
	if(res[1]=='r')return 0;
	exit(0);
}
bool answer(int x){
/*	assert(x==ans);
	cout<<cnt<<endl;*/
	cout<<"! "<<x<<endl;
	return 0;
}
int query(int l,int r){
	if(l==r)return l;
	if(l+1==r)return ask(l+1)?l+1:l;
	++r;
	int xl=(l+l+r)/3,xr=(l+r+r)/3;
	if(ask(xl)){
		if(ask(xr)){
			return query(xr,r-1);
		}
		return query(xl,xr-1);
	}
	else{
		if(l+1!=xl)ask(l);
		return query(l,xl-1);
	}
}
int work(){
	int rm=45;
	for(int i=0;i<=45;++i){
		if(!ask(1ll<<i)){rm=i-1;break;}
	}
	if(rm<0)return answer(0);
	if(rm<45){
		int st=1ll<<rm,ed=(1ll<<(rm+1))-1;
		ask(1ll<<rm);
		ask(1ll<<rm);
		return answer(query(st,ed));
	}
	if(ask(3ll<<44)){
		if(ask(1ll<<46)){
			return answer(query(1ll<<46,100000000000000ll));
		}
		ask(3ll<<44);
		return answer(query(3ll<<44,(1ll<<46)-1));
	}
	else{
		ask(1ll<<45);
		ask(1ll<<45);
		return answer(query(1ll<<45,(3ll<<44)-1));
	}
	int st=1ll<<rm,ed=min((1ll<<(rm+1))-1,100000000000000ll);
	if(rm!=46){
		ask(1ll<<rm);
		ask(1ll<<rm);
	}
	return answer(query(st,ed));
}
void Judge(int w){
	ans=w;
	cur=1;
	cnt=0;
	work();
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif

	int t;
/*	for(int i=0;i<=1000;++i)Judge((1ll<<45)+i);
	for(int i=0;i<=1000;++i)Judge((3ll<<44)+i);
	for(int i=0;i<=1000;++i)Judge((1ll<<46)+i);
	return 0;*/
	/*t=10;
	//Judge((1ll<<45)+2);
	for(int i=0;i<=1000;++i)Judge(i);
	//for(;t;--t)Judge();
	return 0;*/
	cin>>t;
	for(;t;--t){
		work();
	}
	return 0;
}