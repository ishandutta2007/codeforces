#pragma GCC optimize("Ofast,unroll-loops")
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
int n,a[100005];
V<int> v[50];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
		FOR(j,0,30){
			if(a[i]&(1<<j))v[j].PB(i);
		}
	}
	if(n==1){
		cout<<a[1];RE 0;
	}
	int t=0;
	for(int i=30;i>=0;i--){
		if(v[i].size()==1){
			t=v[i][0];break;
		}
	}
	if(!t){
		FOR(i,1,n)cout<<a[i]<<' ';
	}else{
		cout<<a[t]<<' ';
		FOR(i,1,n)if(i!=t)cout<<a[i]<<' ';
	}
	RE 0;
}