#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 75
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,a[MN],b[MN];
int ans;
vector<int> v[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	int rev=0;
	F(i,1,n){
		int p=0;
		F(j,1,n)if(a[j]==i)p=j;
		if(i==1&&p==n){
			reverse(a+1,a+n+1);
			rev^=1;
			continue;
		}
		if(p==i)continue;
		++ans;
		if(!rev){
			F(j,1,i-1)v[ans].pb(1);
			v[ans].pb(p-i+1);
			F(j,p+1,n)v[ans].pb(1);
		}else{
			F(j,p+1,n)v[ans].pb(1);
			v[ans].pb(p-i+1);
			F(j,1,i-1)v[ans].pb(1);
		}
		reverse(a+i,a+p+1);
		rev^=1;
	}
	if(rev&&n>1){
		++ans;
		F(i,1,n)v[ans].pb(1);
	}
	printf("%d\n",ans);
	F(i,1,ans){
		printf("%d",(int)v[i].size());
		for(int x:v[i])printf(" %d",x);
		puts("");
	}
	return 0;
}