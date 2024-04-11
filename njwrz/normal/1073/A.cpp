#pragma GCC optimize("Ofast")
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
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin>>n>>s;
	rep(i,0,s.size()-1){
		if(s[i]!=s[i+1]){
			cout<<"YES\n"<<s[i]<<s[i+1];RE 0;
		}
	} 
	cout<<"NO";
	RE 0;
}