#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,q;
int a[MN],p[MN],k[MN],pp[MN];
int nx[MN],c[MN],ans[MN];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	scanf("%d",&q);
	F(i,1,q)scanf("%d%d",p+i,k+i),pp[i]=i;
	sort(pp+1,pp+q+1,[](int i,int j){return k[i]<k[j];});
	F(I,1,q){
		int i=pp[I];
		if(k[i]<=500){
			if(I==1||k[i]!=k[pp[I-1]]){
				F(j,1,n)nx[j]=j+a[j]+k[i];
				dF(j,n,1)c[j]=nx[j]>n?1:1+c[nx[j]];
			}
			ans[i]=c[p[i]];
		}else{
			int ansn=0;
			int P=p[i],K=k[i];
			while(P<=n)P=P+a[P]+K,++ansn;
			ans[i]=ansn;
		}
	}
	F(I,1,q)printf("%d\n",ans[I]);
}	return 0;
}