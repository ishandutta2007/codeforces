/*
Author: CNYALI_LK
LANG: C++
PROG: 42.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
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
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
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
int n,a[150005],b[150005];
void chk(int x){
	for(int i=1;i<=n;++i)if((a[i]%x)&&(b[i]%x))return;
	printf("%d\n",x);
	exit(0);
}
void calc(int x){
	for(int i=2;i*i<=x;++i){
		if(!(x%i)){
			while(!(x%i))x/=i;
			chk(i);
		}
	}
	if(x>1)chk(x);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();b[i]=read();
	}
	calc(a[1]);
	calc(b[1]);
	printf("-1\n");
	return 0;
}