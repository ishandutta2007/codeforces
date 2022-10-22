#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
map<P<int,int>,int > m;
void solve(){
	int n;
	m.clear();
	string s;
	cin>>n>>s;
	int x,y;x=y=0;
	int mini=1000000000;
	P<int,int> ans;
	m[MP(0,0)]=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='L'){
			x--;
		}else if(s[i]=='R'){
			x++;
		}else if(s[i]=='U'){
			y++;
		}else y--;
		if(m.count(MP(x,y))){
			int t=m[MP(x,y)];
			if(i-t<mini){
				mini=i-t;
				ans=MP(t+1,i+1);
			}
		}
		m[MP(x,y)]=i+1;
	}
	if(mini==1000000000){
		cout<<"-1\n";
	}else{
		cout<<ans.F<<' '<<ans.S<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}