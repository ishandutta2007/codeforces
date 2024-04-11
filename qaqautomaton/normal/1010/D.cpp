/*
Author: CNYALI_LK
LANG: C++
PROG: CF1010D.cpp
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
int tp[1024242],uc[1024242],lc[1024242],rc[1024242],w[1024242];
void rdtp(int x){
	char c;
	while(!isalpha(c=getchar()));
	if(c=='I'){tp[x]=0;w[x]=read();}
	else if(c=='N'){tp[x]=1;lc[x]=read();rc[x]=0;}
	else if(c=='X'){tp[x]=2;lc[x]=read();rc[x]=read();}
	else if(c=='O'){tp[x]=3;lc[x]=read();rc[x]=read();}
	else if(c=='A'){tp[x]=4;lc[x]=read();rc[x]=read();}
}
void value(int x){
	if(!tp[x])return;
	if(tp[x]==1){value(lc[x]);w[x]=w[lc[x]]^1;return;}
	value(lc[x]);value(rc[x]);
	if(tp[x]==2)w[x]=w[lc[x]]^w[rc[x]];
	if(tp[x]==3)w[x]=w[lc[x]]|w[rc[x]];
	if(tp[x]==4)w[x]=w[lc[x]]&w[rc[x]];
}
void down(int x){
	if(!tp[x])return;
	if(uc[x]){
		uc[lc[x]]=uc[rc[x]]=1;
		down(lc[x]);down(rc[x]);
	}
	else{
		if(tp[x]==3){
			if(w[lc[x]])uc[rc[x]]=1;
			if(w[rc[x]])uc[lc[x]]=1;
		}
		if(tp[x]==4){
			if(!w[lc[x]])uc[rc[x]]=1;
			if(!w[rc[x]])uc[lc[x]]=1;
		}
		down(lc[x]);
		down(rc[x]);
	}
}
int main(){
#ifdef cnyali_lk
	freopen("CF1010D.in","r",stdin);
	freopen("CF1010D.out","w",stdout);
#endif
	int n;
	n=read();
	for(int i=1;i<=n;++i)rdtp(i);
	value(1);
	down(1);
	for(int i=1;i<=n;++i)if(!tp[i])if(!uc[i])putchar('0'+(w[1]^1));else putchar('0'+w[1]);
	return 0;
}