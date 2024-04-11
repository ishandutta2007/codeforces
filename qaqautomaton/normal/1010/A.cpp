/*
Author: CNYALI_LK
LANG: C++
PROG: CF1010A.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
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
char WriteIntBuffer[1024];
template<class T>void write(T a,char end){
	int cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WriteIntBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WriteIntBuffer[cnt]);--cnt;}
	putchar(end);
}
double a[102424],b[102424];
int n;
double m;
double s=1;
int check(double w){
	w=(w+m)*s;
	return w-m>-eps;
}
int main(){
#ifdef cnyali_lk
	freopen("CF1010A.in","r",stdin);
	freopen("CF1010A.out","w",stdout);
#endif
	n=read();m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		s=s*(a[i]-1)/a[i];
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
		s=s*(b[i]-1)/b[i];
	}
	b[n+1]=b[1];
	double l=0,r=1e9+1,mid;
	while(r-l>eps){
		mid=(l+r)/2;
		if(check(mid))r=mid-eps;
		else l=mid+eps;
	}
	if(fabs(r-1e9-1)<=eps)printf("-1\n");
	else
	printf("%.7lf\n",r);

	return 0;
}