#pragma GCC optimize(2)
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
int solve(string x){
	int num1=0,num2=0;
	rep(i,0,5){
		num1+=x[i*2]=='1';
		if(num1+(5-i-1)<num2){
			RE i*2+1;
		}
		if(num2+(5-i)<num1){
			RE i*2+1;
		}
		num2+=x[i*2+1]=='1';
		if(num1+(5-i-1)<num2){
			RE i*2+2;
		}
		if(num2+(5-i-1)<num1){
			RE i*2+2;
		}
	}
	RE 10;
}
void solve(){
	string s;
	cin>>s;
	string ts="",tt="";
	int cnt=0;
	for(auto u:s){
		cnt++;
		if(u=='?'){
			if(cnt&1){
				ts+="1";tt+="0";
			}else{
				ts+="0";tt+="1";
			}
		}else {
			ts+=u;tt+=u;
		}
	}
	cout<<min(solve(ts),solve(tt))<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}