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
int n,a[MN];
int ask(int i){
	printf("? %d\n",i),fflush(stdout);
	scanf("%d",&a[i]);
	return a[i];
}
void solve(int l,int r){
	int len=r-l-1;
	if(!len){
		printf("! %d\n",a[l]<a[r]?l:r);
		return;
	}
	if(len==1){
		int x=ask(l+1);
		if(a[l]<x)printf("! %d\n",l);
		else if(a[r]<x)printf("! %d\n",r);
		else printf("! %d\n",l+1);
		return;
	}
	int mid=(l+r)/2;
	int x=ask(mid),y=ask(mid+1);
	if(x<y)solve(l,mid);
	else solve(mid+1,r);
}
int main(){
	scanf("%d",&n);
	a[0]=a[n+1]=n+1;
	solve(0,n+1);
	return 0;
}