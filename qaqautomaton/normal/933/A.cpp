/*
Author: CNYALI_LK
LANG: C++
PROG: A.cpp
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
int a[2048],cnt0f[2048],cnt1f[2048],s[2048][2048],t[2048][2048];
int cnt0b[2048],cnt1b[2048];
int main(){
#ifdef cnyali_lk
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	int n;
	n=read();
	for(int i=1;i<=n;++i)a[i]=read()-1;
	for(int i=1;i<=n;++i){
		cnt0f[i]=cnt0f[i-1]+(a[i]==0);
		cnt1f[i]=cnt1f[i-1]+(a[i]==1);
	}
	for(int i=n;i;--i){
		cnt0b[i]=cnt0b[i+1]+(a[i]==0);
		cnt1b[i]=cnt1b[i+1]+(a[i]==1);
	}
	for(int i=1;i<=n;++i){
		s[i][i]=1;
		t[i][i]=1;
		for(int j=i+1;j<=n;++j){
			if(a[j]==0){
				s[i][j]=max(s[i][j-1],cnt0f[j]-cnt0f[i-1]);
				t[i][j]=t[i][j-1]+1;
			}
			else{
				s[i][j]=s[i][j-1]+1;
				t[i][j]=max(t[i][j-1],cnt1f[j]-cnt1f[i-1]);
			}
		}
	}
	int ans=s[1][n];
	for(int i=1;i<=n;++i)for(int j=i;j<=n;++j){
		chkmax(ans,cnt0f[i-1]+cnt1b[j+1]+t[i][j]);	
	}
	printf("%d\n",ans);
	return 0;
}