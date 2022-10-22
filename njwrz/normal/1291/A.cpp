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
void solve(){
	int len;
	string s;
	cin>>len>>s;
	int ans1=-1;
	for(int i=0;i<len;i++){
		int t=s[i]-'0';
		if(t&1){
			if(ans1==-1){
				ans1=t;
			}else{
				cout<<ans1<<t<<'\n';RE ;
			}
		}
	}
	cout<<"-1\n";
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin>>n;
	while(n--)solve(); 
	RE 0;
}