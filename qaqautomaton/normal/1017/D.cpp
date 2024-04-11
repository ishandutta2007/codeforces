/*
Author: CNYALI_LK
LANG: C++
PROG: 1017D.cpp
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

int read2(){
	int s=0;
	char c;
	while(!isdigit(c=getchar()));
	while(isdigit(c)){s=(s<<1)+(c^48);c=getchar();}
//	printf("Fafa %d\n",s);
	return s;
}
char WriteIntBuffer[1024];
template<class T>void write(T a,char end){
	int cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WriteIntBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WriteIntBuffer[cnt]);--cnt;}
	putchar(end);
}
int f[4555][4555],w[4555][233],cnt[4555];
int d[15];
int n,m,q,N;
int diff(int x,int y){
	int ans=0;
	for(int i=0;i<n;++i)if((x&(1<<i))==(y&(1<<i)))ans+=d[i];
	if(ans>100)ans=101;
//	printf("Diff(%d,%d)=%d\n",x,y,ans);
	return ans;
}
int main(){
#ifdef cnyali_lk
	freopen("1017D.in","r",stdin);
	freopen("1017D.out","w",stdout);
#endif
	n=read();m=read();q=read();
	N=1<<n;
	for(int i=n-1;~i;--i)d[i]=read();
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)f[i][j]=diff(i,j);
	for(int i=1;i<=m;++i){
		++cnt[read2()];
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j)w[i][f[i][j]]+=cnt[j];
		for(int j=1;j<=100;++j)w[i][j]+=w[i][j-1];
	}
	for(;q;--q){
		int x=read2(),y=read();
		printf("%d\n",w[x][y]);
	}
	
	return 0;
}