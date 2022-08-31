/*
Author: CNYALI_LK
LANG: C++
PROG: 1019B.cpp
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
int x;
int n,v1,v2,m;
void Put(int x){
	printf("! %d\n",x);
	exit(0);
}
int Query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int a1,a2;
	scanf("%d",&a1);
	printf("? %d\n",x+m);
	fflush(stdout);
	scanf("%d",&a2);
	if(a1==a2)Put(x);
	if(a1<a2)return -1;
	else return 1;
	return x;
}
int main(){
	n=read();
	m=n>>1;
	v1=Query(1);
	int l=2,r=m,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(Query(mid)!=v1)r=mid-1;
		else l=mid+1;
	}		
	Put(-1);
	return 0;
}