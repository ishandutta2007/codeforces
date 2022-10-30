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
int n,k,a[200005];
bool check(int x){
	rep(t,0,2){
		int p=t,cnt=0;
		FOR(i,1,n){
			if(!p){
				p^=1;cnt++;
			}else if(a[i]<=x){
				p^=1;cnt++;
			}
		}
		if(cnt>=k){
			RE 1;
		}
	}
	RE 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	V<int> v;
	FOR(i,1,n)cin>>a[i],v.PB(a[i]);
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	FOR(i,1,n)a[i]=lwb(ALL(v),a[i])-v.begin()+1;
	int l=1,r=v.size(),mid,ans;
	while(r>=l){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<v[ans-1];
	RE 0;
}