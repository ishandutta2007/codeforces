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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int cnt[100005];
V<P<int,int> > op;
void DO(int x,int y){
	assert(cnt[x]>0);
	assert(cnt[y]>0);
	cnt[x]--;
	cnt[y]--;
	cnt[abs(x-y)]++;
	cnt[x+y]++;
	op.PB(MP(x,y));
}
void solve(int x,int d){
	if(x<=2)RE ;
	int p=1;
	while(p*2<=x)p*=2;
	if(p==x){
		solve(x-1,d);RE;
	}
	int l=p-1,r=p+1;
	while(l>=1&&r<=x){
		DO(l*d,r*d);
		l--;r++;
	}
	solve(x-p,d*2);
	solve(2*p-x-1,d);
}
void solve(){
	op.clear();
	int n;
	cin>>n;
	if(n==2){
		cout<<-1<<'\n';RE ;
	}
	FOR(i,0,n*2)cnt[i]=0;
	FOR(i,1,n)cnt[i]=1;
	solve(n,1);
	int t=1;
	while(t<n)t*=2;
	rep(i,0,20)if((1<<i)<n&&cnt[(1<<i)]){
		while(cnt[1<<i]>1)DO(1<<i,1<<i);
	}
	rep(i,0,20)if((1<<i)<n&&cnt[(1<<i)]){
		if(cnt[(1<<i)]&1){
			if(!cnt[0]){
				cout<<-1<<'\n';RE ;
			}
			DO(0,(1<<i));
		}
		while(cnt[1<<i])DO(1<<i,1<<i);
	}
	while(cnt[0])DO(0,t);
	cout<<op.size()<<'\n';
	for(auto u:op)cout<<u.F<<' '<<u.S<<'\n';
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}