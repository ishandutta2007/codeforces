#pragma GCC optimize(3)
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
string s;
bool check(int x1,int x2,int x3){
	x3-=x1;
	if(x3<0&&x2>0||x3>0&&x2<0)RE 0;
	RE x3%x2==0;
} 
void solve(){
	int n,m;
	cin>>n>>m;
	cin>>s;
	int t1,t0;
	t1=t0=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')t1++;else t0++;
	}
	if(t1==t0){
		int q1=0,q0=0;
		for(int i=0;i<s.size();i++){
			if(q0-q1==m){
				cout<<"-1\n";RE;
			}
			if(s[i]=='1')q1++;else q0++;
		} 
		cout<<"0\n";RE;
	}
	int q1=0,q0=0,ans=0;
	for(int i=0;i<s.size();i++){
		if(check(q0-q1,t0-t1,m)){
			ans++;
		}
		if(s[i]=='1')q1++;else q0++;
	} 
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}