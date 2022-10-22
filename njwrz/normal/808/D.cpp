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
map<int,int> mp,mp2;
int a[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i],mp[a[i]]++;
	int sum=0;
	FOR(i,1,n)sum+=a[i];
	if(sum&1){
		cout<<"NO";RE 0;
	}
	int t=sum/2;
	FOR(i,1,n){
		mp[a[i]]--;mp2[a[i]]++;
		sum-=a[i];
		if(sum>t){
			if(mp[sum-t]>0){
				cout<<"YES";RE 0; 
			}
		}else{
			if(mp2[t-sum]>0){
				cout<<"YES";RE 0;
			}
		}
	}
	cout<<"NO";
	RE 0;
}