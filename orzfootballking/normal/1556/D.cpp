#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
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
#define lc (x<<1)
#define rc ((x<<1)^1)
using namespace std;
int n,a[10005],k;
int f1[10005],f2[10005],tval;
signed main(){
	cin>>n>>k;
	FOR(i,2,n){
		cout<<"or "<<1<<' '<<i<<'\n';
		fflush(stdout);
		cin>>f1[i];
	}
	FOR(i,2,n){
		cout<<"and "<<1<<' '<<i<<'\n';
		fflush(stdout);
		cin>>f2[i];
	}
	cout<<"and "<<2<<' '<<3<<'\n';
	fflush(stdout);cin>>tval;
	FOR(p,0,30){
		int now=-1;
		FOR(i,2,n){
			if(!(f1[i]&(1<<p)))now=0;
			if(f2[i]&(1<<p))now=1;
		}
		if(now==-1){
			if(tval&(1<<p)){
				now=0;
			}else now=1;
		}
		a[1]+=now*(1<<p);
		if(now){
			FOR(i,2,n)if(f2[i]&(1<<p)){
				a[i]+=(1<<p);
			}
		}else{
			FOR(i,2,n)if(f1[i]&(1<<p)){
				a[i]+=(1<<p);
			}
		}
	}
	sort(a+1,a+n+1);
	cout<<"finish "<<a[k]<<'\n';fflush(stdout);
	RE 0;
}