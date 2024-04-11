#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
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
void solve(){
	string s;
	cin>>s;
	int l=-1,r=-1;
	rep(i,0,s.size()){
		if(s[i]=='1'){
			l=i;break;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='1'){
			r=i;break;
		}
	}
	if(l==-1){
		cout<<"0\n";RE;
	}
	int ans=0;
	rep(i,0,s.size()){
		if(s[i]=='0')ans++;
	}
	ans-=l+s.size()-r-1;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	while(n--)solve();
	RE 0;
}