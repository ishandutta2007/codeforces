#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

int n,q;
int a[100001];
int b[100001];
int l[256];

int main(){
	scanf("%d%d",&n,&q);
	F(i,1,n) scanf("%d",a+i);
	memset(l,-1,sizeof l);
	F(i,1,n){
		if(l[a[i]]!=-1) {b[i]=l[a[i]]; continue;}
		int L=max(0,a[i]-q+1);
		if(l[L]==-1){
			b[i]=L;
			F(j,L,a[i]) l[j]=L;
		}
		else{
			int e=L;
			while(l[e]<L&&l[e]!=-1) ++e;
			b[i]=e;
			F(j,e,a[i]) l[j]=e;
		}
	}
	F(i,1,n) printf("%d ",b[i]);
	return 0;
}