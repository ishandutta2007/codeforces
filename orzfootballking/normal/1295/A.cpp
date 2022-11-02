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
void solve(){
	int n;
	cin>>n;
	if(n&1){
		cout<<'7';
		for(int i=1;i<n/2;i++)cout<<'1';
		cout<<"\n";
	}else {
		for(int i=1;i<=n/2;i++)cout<<'1';
		cout<<'\n';
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