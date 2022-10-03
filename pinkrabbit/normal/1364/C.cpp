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
int n;
int a[MN],b[MN],c[MN],d[MN],m;
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),c[a[i]]=1;
	F(i,1,n)if(!c[i])d[++m]=i;
	int j=0;
	F(i,1,n){
		if(a[i]==a[i-1])printf("%d ",d[++j]);
		else printf("%d ",a[i-1]);
	}
	return 0;
}