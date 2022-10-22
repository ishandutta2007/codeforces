#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int cnt,p[1005],a[14]; 
int ct(int x){
	if(!x)RE 0;
	RE ct(x/2)+(x&1);
}
int q[14][1005],l[14],ans[1005];
signed main(){
	int n;
	scanf("%lld",&n);
	rep(i,(1<<5)-1,1<<13){
		if(ct(i)==5){
			if(cnt<n){
				p[++cnt]=i;
			}else break;
		}
	}
	FOR(i,1,n){
		rep(j,0,13){
			if(p[i]&(1<<j))q[j+1][++l[j+1]]=i;
		}
	}
	FOR(i,1,13){
		if(!l[i])break;
		printf("? %lld ",l[i]);
		FOR(j,1,l[i])printf("%lld ",q[i][j]);
		puts("");
		fflush(stdout);
		scanf("%lld",&a[i]);
	}
	FOR(i,1,n){
		rep(j,0,13){
			if(!(p[i]&(1<<j))){
				ans[i]|=a[j+1];
			}
		}
	}
	printf("! ");
	FOR(i,1,n)printf("%lld ",ans[i]);
	puts("");
	fflush(stdout);
	RE 0;
}