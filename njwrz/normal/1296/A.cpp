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
int a[2005],n;
void solve(){
	cin>>n;bool f1,f2;f1=f2=0;
	FOR(i,1,n){
		cin>>a[i];if(a[i]&1)f1=1;else f2=1;
	}
	if(!f1||(!(n&1)&&!f2)){
		cout<<"NO\n";
	}else cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}