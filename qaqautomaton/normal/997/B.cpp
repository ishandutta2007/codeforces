/*
Author: CNYALI_LK
LANG: C++
PROG: B.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %I64d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %I64d\n",__FUNCTION__,__LINE__)
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
int main(){
#ifdef cnyali_lk
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	ll n,cnt=0;
	n=read();
	if(n<=20)
	for(ll i=0;i<=n;++i)
		for(ll j=0;j<=n-i;++j)
			for(ll k=0;k<=n-i-j;++k)if((j>=9)||(k>=9)||(k>=5&&j))continue;
			else{
				++cnt;
			}
	else{
		cnt=0;
		for(ll i=0;i<9;++i)for(ll j=0;j<9;++j)if(i<5||!j){
			cnt+=(n-i-j+1);
		}
	}

	printf("%I64d\n",cnt);
	return 0;
}