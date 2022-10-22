/*

DP





ll int
 dp 










*/
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
char c1,c2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>c2;
	c1-='a';c2-='1';
	int f1=(c1==0)||(c1==7),f2=(c2==0)||(c2==7);
	if(f1&&f2){
		cout<<3;
	}else if(f1||f2){
		cout<<5;
	}else cout<<8;
	RE 0;
}