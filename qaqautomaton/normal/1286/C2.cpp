/*
Author: QAQAutomaton
Lang: C++
Code: C.cpp 
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
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
struct __INIT__{
	__INIT__(){
		memset(&inf,0x3f,sizeof(inf));
	}
}__INIT___;

char s[105];
int w[105],su[105];
int ans[106];
int iss[106];
vector<pii> to[105];
void add(int l,int r,int s){
	if(l==r){iss[l]=1;ans[l]=s>>1;return;}
	to[l].push_back(make_pair(r,s));
	to[r].push_back(make_pair(l,s));
}
void work(int ls,int rs){
	printf("? %d %d\n",ls,rs);
	fflush(stdout);
	int n=rs-ls+1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j)w[i]=0;
	}
	for(int i=1;i<=n*(n+1)/2;++i){
		scanf("%s",s);
		int l=strlen(s);
		for(int j=0;j<l;++j){
			w[l]+=s[j]-'a';
		}
	}
	for(int l=ls,r=rs,i=1;l<=r;++l,--r,++i){
		su[i]=w[n]*(i+1)-w[n-i];
		for(int j=1;j<i;++j)su[i]-=(i-j+1)*su[j];
		add(l,r,su[i]);
	}
}
int *l,*r,q[105];
signed main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("? %d %d\n",1,n);
		fflush(stdout);
		scanf("%s",s);
		printf("! %s\n",s);
		fflush(stdout);
		return 0;
	}
	int mid=(1+n)>>1;
	work(1,n);
	work(1,mid);
	if(n&1)work(mid+1,n);
	else work(mid,n);
	l=q+1;r=q;
	for(int i=1;i<=n;++i)if(iss[i])*(++r)=i;
	while(l<=r){
		for(auto i:to[*l])if(!iss[i.x]){
			iss[i.x]=1;ans[i.x]=i.y-ans[*l];
			*(++r)=i.x;
		}
		++l;
	}
	putchar('!');
	putchar(' ');
	for(int i=1;i<=n;++i)putchar(ans[i]+'a');
	putchar('\n');
	fflush(stdout);	
	return 0;
}