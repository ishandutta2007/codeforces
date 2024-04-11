/*
Author: QAQAutoMaton
Lang: C++
Code: F.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(qaq...) fprintf(stderr,qaq)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())
using namespace std;
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cp;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T,class T2>int chkmin(T &a,T2 b){return a>b?a=b,1:0;}
template<class T,class T2>int chkmax(T &a,T2 b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char*)&inf,(unsigned char*)&inf+sizeof(inf),0x3f);
	}
}__INIT___;
namespace run{
	int a[55][55];
	int id[55];
	int rk[55][55],xv[55][55];
	int lnk[105];
	int stk[55];
	int cur[55];
	int mx[105];
	bool main(){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)cin>>a[i][j];
		cout<<'B'<<endl;
		char ch;
		int x;
		cin>>ch>>x;
		for(int i=1;i<=n;++i)id[i]=i;
		if((ch=='D')!=(x>n))for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)a[i][j]=-a[i][j];
		for(int i=1;i<=n+n;++i)lnk[i]=0;
		for(int i=1;i<=n;++i){
			sort(id+1,id+n+1,[&](int x,int y){return a[i][x]>a[i][y];});
			for(int j=1;j<=n;++j)xv[i][j]=id[j],rk[i][id[j]]=j;
		}
		int t=0;
		for(int i=1;i<=n;++i){
			stk[++t]=i;		
			cur[i]=n;
		}
		while(t){
			int x=stk[t];--t;
			int y=xv[x][cur[x]];
			if(!lnk[y+n]){
				lnk[y+n]=x;lnk[x]=y+n;continue;
			}
			else if(a[x][y]>a[lnk[y+n]][y]){
				int z=lnk[y+n];lnk[y+n]=x;--cur[z];stk[++t]=z;
				lnk[x]=y+n;
			}
			else {--cur[x];stk[++t]=x;}
		}
		while(1){
			cout<<lnk[x]<<endl;
			cin>>x;
			if(x==-1)return 0;
			if(x==-2)exit(0);
		}
	}
}
signed main(){
	int t;
	cin>>t;	
	for(;t;--t){
		run::main();
	}
	return 0;
}