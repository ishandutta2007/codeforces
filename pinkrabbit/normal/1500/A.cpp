#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MS 2500005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n;
int a[MN],p[MN];
int b[MS];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),p[i]=i;
	sort(p+1,p+n+1,[](int i,int j){return a[i]<a[j];});
//	F(i,4,n)if(a[p[i-3]]==a[p[i]])
//		return printf("YES\n%d %d %d %d\n",p[i-3],p[i-2],p[i-1],p[i]),0;
	if(n>=4000){
		b[a[p[2]]-a[p[1]]]=2;
		F(i,4,n){
			int v=a[p[i]]-a[p[i-1]];
			if(b[v])
				return printf("YES\n%d %d %d %d\n",p[b[v]],p[i-1],p[b[v]-1],p[i]),0;
			b[a[p[i-1]]-a[p[i-2]]]=i-1;
		}
		return 0;
	}
	b[a[p[2]]-a[p[1]]]=2;
	F(i,3,n-1){
		F(j,i+1,n){
			int v=a[p[j]]-a[p[i]];
			if(b[v]){
				int x=0;
				F(k,1,b[v]-1)if(a[p[b[v]]]-a[p[k]]==v){x=k;break;}
				printf("YES\n%d %d %d %d\n",p[b[v]],p[i],p[x],p[j]);
				return 0;
			}
		}
		F(j,1,i-1)
			b[a[p[i]]-a[p[j]]]=i;
	}
	puts("NO");
	return 0;
}