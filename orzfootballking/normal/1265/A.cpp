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
	s="?"+s+"?";
	rep(i,1,s.size()-1){
		if(s[i]!='?')continue;
		if(s[i-1]!='a'&&s[i+1]!='a'){
			s[i]='a';
		}else if(s[i-1]!='b'&&s[i+1]!='b'){
			s[i]='b';
		}else if(s[i-1]!='c'&&s[i+1]!='c'){
			s[i]='c';
		}
	}
	rep(i,1,s.size()-2){
		if(s[i]==s[i+1]){
			cout<<"-1\n";RE;
		}
	}
	rep(i,1,s.size()-1)cout<<s[i];
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}