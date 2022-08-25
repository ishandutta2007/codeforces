/*
Author: CNYALI_LK
LANG: C++
PROG: A.cpp
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
char s[302424];
int main(){
#ifdef cnyali_lk
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	ll n,x,y,z=0,o=0;
	scanf("%I64d%I64d%I64d\n%s",&n,&y,&x,s+1);
	for(ll i=1;i<=n;++i){
		if(s[i]==s[i-1]);
		else if(s[i]=='1')++o;
		else ++z;
	}
	if(!z)printf("0\n");
	else if(x<y)printf("%I64d\n",z*x);
	else printf("%I64d\n",(z-1)*y+x);

	return 0;
}