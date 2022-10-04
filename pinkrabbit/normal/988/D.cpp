#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
#define For(i,a) for(int i=1;i<=a;++i)
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dFor(i,a) for(int i=a;i>=1;--i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
#define eF(h,i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
int n,m,k;
long long a[200001],A2,B2;
set<long long> st;
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%lld",a+i), st.insert(a[i]);
	F(i,1,n){
		F(j,0,30){
			long long kk=a[i]-(1ll<<j);
			long long jj=a[i]+(1ll<<j);
			if(st.count(kk)==1&&st.count(jj)==1){
				puts("3");
				printf("%lld %lld %lld",kk,jj,a[i]);
				return 0;
			}
			if(st.count(kk)==1||st.count(jj)==1){
				if(st.count(kk)==1) A2=a[i], B2=kk;
				else A2=a[i], B2=jj;
			}
		}
	}
	if(A2||B2){
		printf("2\n%lld %lld",A2,B2);
	}
	else printf("1\n%lld",a[1]);
	return 0;
}