/*
Author: CNYALI_LK
LANG: C++
PROG: 1019A.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<ll,ll> pii;
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
ll read(){
	ll s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
char WritellBuffer[1024];
template<class T>void write(T a,char end){
	ll cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WritellBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WritellBuffer[cnt]);--cnt;}
	putchar(end);
}
vector<ll> a[102424];
priority_queue<ll,vector<ll>,greater<ll> > p;
int main(){
#ifdef cnyali_lk
	freopen("1019A.in","r",stdin);
	freopen("1019A.out","w",stdout);
#endif
	ll n,m,pa;
	n=read();
	m=read();
	for(ll i=1;i<=n;++i){
		pa=read();
		a[pa].push_back(read());
	}
	for(ll i=1;i<=m;++i){
		sort(a[i].begin(),a[i].end(),[](ll a,ll b){return a>b;});
	}
	ll xmin=0x3f3f3f3f3f3f3f3f,cnt1=0,t=0,fafa,w;
	for(ll i=n;i>=a[1].size()&&i;--i){
		while(!p.empty())p.pop();
		for(ll j=2;j<=m;++j){
			if(a[j].size()>=i){
				cnt1+=*a[j].rbegin();
				++t;
				a[j].pop_back();
			}
			for(auto k:a[j])p.push(k);
		}
		w=cnt1;
		fafa=t+a[1].size();
		for(;fafa<i;++fafa){w+=p.top();p.pop();}
		chkmin(xmin,w);
	}
	printf("%lld\n",xmin);
	return 0;
}