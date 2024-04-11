#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m,l[5005],r[5005],a[5005],mod=1e9+7,ans,cnt;
V<int> v[5005];
void check(P<int,int> t){
	if(t.F>ans){
		ans=t.F;cnt=t.S;
	}else if(t.F==ans){
		cnt=(cnt+t.S)%mod;
	}
}
P<int,int> solve(int x,int y){
	int an=0,cn=1,maxi,mini,t,tl;
	FOR(i,1,n){
		if(x==i){
			an++;
			if(v[i].size()>1&&v[i][0]<=r[i]){
				t=0;
				for(auto u:v[i]){
					if(u<=r[i])t++;else break;
				}
				if(r[i]>=l[i])t--;
				if(t){
					an++;cn=cn*t%mod;
				}
			}
			continue;
		}
		maxi=max(r[i],l[i]);
		mini=min(r[i],l[i]);
		if(v[i].size()>1&&maxi>=v[i][1]&&mini>=v[i][0]){
			tl=t=0;
			for(auto u:v[i]){
				if(u<=maxi)tl++;
				if(u<=mini)t++;
			}
			if(t*(tl-1)){
				an+=2;
				cn=cn*t%mod*(tl-1)%mod;
				continue;
			}
		}
		if(v[i].size()&&v[i][0]<=maxi){
			t=0;
			for(auto u:v[i]){
				if(u<=maxi)t++;
				if(u<=mini)t++;
			}
			an++;
			cn=cn*t%mod;
		}
	}
	RE MP(an,cn);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;int x,y;
	FOR(i,1,n){
		cin>>a[i];r[a[i]]++;
	}
	FOR(i,1,m){
		cin>>x>>y;v[x].PB(y);
	}
	FOR(i,1,n)sort(ALL(v[i]));
	P<int,int> t=solve(0,0);
	check(t);
	FOR(i,1,n){
		l[a[i]]++;r[a[i]]--;
		for(auto u:v[a[i]]){
			if(u==l[a[i]]){
				t=solve(a[i],l[a[i]]);
				check(t);
				break;
			}
		}
	}
	cout<<ans<<' '<<cnt;
	RE 0;
}