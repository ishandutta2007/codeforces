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
int n;
int a[500005],b[500005],p[500005];
int maxi[500005],len;
int solve(int l,int r,int tl,int tr){
	FOR(i,1,len)maxi[i]=0;
	len=0;
	FOR(i,l,r){
		if(p[i]>=tl&&p[i]<=tr){
			int t=upb(maxi+1,maxi+len+1,-p[i])-maxi;
			if(t>len)len=t;
			maxi[t]=-p[i];
		}
	}
	RE len;
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>n>>k;
	V<int> v;
	FOR(i,1,n)cin>>a[i],p[i]=i-a[i],v.PB(p[i]);
	FOR(i,1,k)cin>>b[i];
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	FOR(i,1,n)p[i]=lwb(ALL(v),p[i])-v.begin()+1;
	int ans=k;
	if(!k){
		cout<<n-solve(1,n,1,n);RE 0;
	}
	ans+=solve(1,b[1]-1,p[b[1]],n);
	FOR(i,2,k){
		if(p[b[i]]>p[b[i-1]]){
			cout<<-1;RE 0;
		}
		ans+=solve(b[i-1]+1,b[i]-1,p[b[i]],p[b[i-1]]);
	}
	ans+=solve(b[k]+1,n,1,p[b[k]]);
	cout<<n-ans;
	RE 0;
}