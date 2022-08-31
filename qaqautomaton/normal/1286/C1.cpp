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
struct dt{
	int a[26];
	int &operator [](int x){return a[x];}
	dt operator +(dt b){
		dt c;
		for(int i=0;i<26;++i)c[i]=a[i]+b[i];
		return c;
	}
	dt operator -(dt b){
		dt c;
		for(int i=0;i<26;++i)c[i]=a[i]-b[i];
		return c;
	}
	dt operator -(int b){
		dt c;
		for(int i=0;i<26;++i)c[i]=a[i];
		--c[b];
		return c;
	}
	dt operator -(char b){
		dt c;
		for(int i=0;i<26;++i)c[i]=a[i];
		--c[b-'a'];
		return c;
	}
};
dt w[106];
signed main(){
	int n;
	scanf("%d",&n);
	printf("? %d %d\n",1,n);
	fflush(stdout);
	for(int i=1;i<=n*(n+1)/2;++i){
		scanf("%s",s);	
		int l=strlen(s);
		for(int j=0;j<l;++j)++w[l][s[j]-'a'];
	}
	if(n==1){printf("! %s\n",s);fflush(stdout);return 0;}
	printf("? %d %d\n",2,n);
	fflush(stdout);
	for(int i=1;i<=n*(n-1)/2;++i){
		scanf("%s",s);	
		int l=strlen(s);
		for(int j=0;j<l;++j)--w[l][s[j]-'a'];
	}
	for(int i=n;i;--i)w[i]=w[i]-w[i-1];
	printf("! ");
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j)if(w[i][j])printf("%c",j+'a');
	}
	putchar('\n');
	fflush(stdout);	
	return 0;
}