/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
bool f[2005];
void solve(){
	int n;
	FILL(f,0);
	scanf("%d",&n);
	int r=0;
	FOR(i,2,n){
		if(!r){
			printf("? %d %d\n",i-1,1);
			FOR(j,1,i-1)printf("%d ",j);printf("\n");
			printf("%d\n",i);
		}else{
			printf("? %d %d\n",1,1);
			printf("%d\n",r);
			printf("%d\n",i);
		}
		fflush(stdout);
		int sum=0;
		scanf("%d",&sum);
		if(sum!=0){
			f[i]=1;
			if(!r){
				r=i;
			}
		}
	}
	int l=1,mid,ans,pp=r;r--;
	while(l<=r){
		mid=(l+r)>>1;
		printf("? %d %d\n",mid,1);
		FOR(j,1,mid)printf("%d ",j);printf("\n");
		printf("%d\n",pp);
		fflush(stdout);
		int sum=0;
		scanf("%d",&sum);
		if(sum==0){
			l=mid+1;
		}else ans=mid,r=mid-1;
	}
	f[ans]=1;
	V<int> ansv;
	FOR(i,1,n){
		if(!f[i])ansv.PB(i);
	}
	cout<<"! "<<ansv.size()<<' ';
	for(auto u:ansv){
		cout<<u<<' ';
	}
	printf("\n");
	fflush(stdout);
}
signed main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	RE 0;
}