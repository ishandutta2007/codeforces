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
char c[100005];
int k;
void solve(){
	int n;
	cin>>n>>k;
	FOR(i,1,n)cin>>c[i];
	int cnt=0;
	V<int> v;
	int l;
	FOR(i,1,n){
		if(c[i]=='W'){
			l=i-1;break;
		}
	}
	int r=0;
	for(int i=n;i>=1;i--){
		if(c[i]=='W'){
			r=i+1;break;
		}
	}
	if(!r){
		cout<<max(0,k*2-1)<<'\n';RE ;
	}
	int len=0;
	rep(i,l+1,r){
		if(c[i]=='L'){
			len++;
		}else{
			if(len){
				v.PB(len);
			}
			if(c[i-1]=='W')cnt+=2;
			else cnt++;
			len=0;
		}
	}
//	cout<<cnt<<'\n';
	sort(ALL(v));
	for(auto u:v){
		if(k>=u){
			cnt+=u*2+1;k-=u;
		}else {
			cnt+=k*2;
			k=0;break;
		}
	}
	r=n-r+1;l+=r;
	if(k){
		if(l){
			cnt+=min(k,l)*2;
		}
	}
	cout<<cnt<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}