/*

DP





ll int
 dp 










*/
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
int a[1000005],cnt,k;
string s;
bool check(int x){
	int count=1,len=0;
	FOR(i,1,cnt){
		if(a[i]+1>x||count>k)RE 0;
		if(len+a[i]+1<=x){
			len+=a[i]+1;
		}else {
			len=a[i]+1;
			count++;
		}
	}
	RE count<=k;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>k;
	cin.get();
	getline(cin,s);
	int len=0;
	int ans=0,l,r,mid;
	for(auto u:s){
		if(u=='-'||u==' '){
			a[++cnt]=len;ans+=len+1;
			len=0;
		}else len++;
	}
	a[++cnt]=len;ans+=len;
	a[cnt]--;
//	cout<<check(8);RE 0;
	l=1,r=ans;
	while(r>=l){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<ans;
	RE 0;
}