/*
Author: CNYALI_LK
LANG: C++
PROG: C.cpp
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
int a[5050],f[5050][2505][3];
/*
0 -1
0  0  0
0  1  1
1  0  2
 */
int main(){
#ifdef cnyali_lk
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n;	
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	memset(f,0x3f,sizeof(f));
	f[1][0][0]=f[1][1][2]=0;
	f[2][0][0]=0;
	f[2][1][1]= a[1]<=a[2]?a[2]-a[1]+1:0;
	f[2][1][2]= a[1]>=a[2]?a[1]-a[2]+1:0;
	int st=(n+1)>>1;
	for(int i=3;i<=n;++i){
		f[i][0][0]=0;	
		int lsd=0,thd=0,lsdd=0,a1=a[i],a2=a[i-1],a3=a[i-2];
		if(a[i]>=a[i-1])thd=a[i]-a[i-1]+1;
		if(a[i]<=a[i-1])lsd=a[i-1]-a[i]+1;
		if(a1<a3&&a1<=a2){if(a2<a3)lsdd=lsd;else lsdd=a3-a1;}
		for(int j=1;j<=st;++j){
			chkmin(f[i][j][0],f[i-1][j][0]);
			chkmin(f[i][j][0],f[i-1][j][1]);
			chkmin(f[i][j][1],f[i-1][j][2]+thd);
			chkmin(f[i][j][2],f[i-1][j-1][0]+lsd);
			chkmin(f[i][j][2],f[i-1][j-1][1]+lsdd);
		}
	}
	for(int i=1;i<=st;++i)printf("%d%c",min(min(f[n][i][0],f[n][i][2]),f[n][i][1]),i==st?'\n':' ');
	return 0;
}