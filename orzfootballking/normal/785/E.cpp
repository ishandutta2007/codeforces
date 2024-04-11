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
const int len=1000;
int a[200005],n,ans;
V<int> s[205]; 
int findmax(int l,int r,int x){
	if(l>r)RE 0;
	int re=0;r++;
	while(l<r&&l%len){
		re+=a[l]>x;
		l++;
	}
	while(r>l&&r%len){
		r--;
		re+=a[r]>x;
	}
	int tl=l/len,tr=r/len;
	while(tl<tr){
		re+=len-(upb(ALL(s[tl]),x)-s[tl].begin());
		tl++;
	}
	RE re;
}
int findmin(int l,int r,int x){
	if(l>r)RE 0;
	int re=0;r++;
	while(l<r&&l%len){
		re+=a[l]<x;
		l++;
	}
	while(r>l&&r%len){
		r--;
		re+=a[r]<x;
	}
	int tl=l/len,tr=r/len;
	while(tl<tr){
		re+=upb(ALL(s[tl]),x)-s[tl].begin();
		tl++;
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	rep(i,0,n)s[i/len].PB(i+1),a[i]=i+1;
	int l,r;
	rep(i,0,m){
		cin>>l>>r;l--,r--;
		if(l>r)swap(l,r);
		if(l==r){
			cout<<ans<<'\n';
			continue;
		}
		ans+=findmax(l+1,r-1,a[l])+findmin(l+1,r-1,a[r]);
		ans-=findmax(l+1,r-1,a[r])+findmin(l+1,r-1,a[l]);
		ans+=a[l]<a[r]?1:-1;
		cout<<ans<<'\n';
		s[l/len].erase(lwb(ALL(s[l/len]),a[l]));
		s[r/len].erase(lwb(ALL(s[r/len]),a[r]));
		s[l/len].insert(upb(ALL(s[l/len]),a[r]),a[r]);
		s[r/len].insert(upb(ALL(s[r/len]),a[l]),a[l]);
		swap(a[l],a[r]);
	}
	RE 0;
}