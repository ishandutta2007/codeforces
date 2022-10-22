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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;n<<=1;
	int a[n];
	rep(i,0,n)cin>>a[i];
	sort(a,a+n);
	int sum=0;
	rep(i,0,n)sum+=(i<n/2)?a[i]:-a[i];
	if(!sum){
		cout<<"-1";
	}else{
		rep(i,0,n){
			cout<<a[i]<<' ';
		}
	}
	RE 0;
}