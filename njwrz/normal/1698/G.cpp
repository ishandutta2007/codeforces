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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int val;
int f[35];
int n;
map<int,int> mp;
int t[50005];
const int B=5e4;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	n=s.size();
	rep(i,0,n)f[i]=s[i]-'0',val+=f[i]<<i;
	int st=-1;
	rep(i,0,n)if(f[i]){
		st=i;break;
	}
	if(st==-1){
		cout<<-1;RE 0;
	}
	val>>=st;
	int ans1=st+1;
	if(__builtin_popcount(val)==1){
		cout<<ans1<<' '<<ans1+1;RE 0;
	}
	t[0]=1;
	mp[1]=0;
	FOR(i,1,B){
		if(t[i-1]&1){
			t[i]=t[i-1]^val;t[i]/=2;
		}else t[i]=t[i-1]/2;
		if(i<B)mp[t[i]]=i;
	}
	int ans2=0;
	int now=1;
	int lim=(1ll<<n)/B;
	FOR(_,1,lim+5){
		int to=0;
		rep(i,0,n)if(now&(1ll<<i)){
			to^=t[B-i];
		}
		ans2+=B;
		if(mp.count(to)){
			cout<<ans1<<' '<<ans2+ans1-mp[to]<<'\n';RE 0;
		}
		now=to;
	}
	cout<<-1;
	RE 0;
}