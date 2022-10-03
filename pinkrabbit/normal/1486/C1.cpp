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
int ask(int l,int r){
	if(l==r)return 0;
	printf("? %d %d\n",l,r),fflush(stdout);
	int x;scanf("%d",&x);return x;
}
void solve(int l,int r,int p){
	if(l==r)return printf("! %d\n",l),void();
	if(l+1==r)return printf("! %d\n",l^r^p),void();
	int mid=(l+r)>>1;
	if(p<=mid){
		int q=ask(l,mid);
		if(q==p)solve(l,mid,q);
		else{
			int lb=mid+1,rb=r,ans=0;
			while(lb<=rb){
				int m=(lb+rb)>>1;
				if(ask(l,m)==p)ans=m,rb=m-1;
				else lb=m+1;
			}
			printf("! %d\n",ans);
		}
	}else{
		int q=ask(mid+1,r);
		if(q==p)solve(mid+1,r,q);
		else{
			int lb=l,rb=mid,ans=0;
			while(lb<=rb){
				int m=(lb+rb)>>1;
				if(ask(m,r)==p)ans=m,lb=m+1;
				else rb=m-1;
			}
			printf("! %d\n",ans);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int p=ask(1,n);
	solve(1,n,p);
	return 0;
}