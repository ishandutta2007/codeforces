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
int a[300005],n;
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int l=1,r=n,t=0;
	while(a[l]>=t){
		t++;l++;
	}
	l--;t=0;
	while(a[r]>=t){
		r--;t++;
	}
	r++;
	if(r<=l)cout<<"Yes\n";else cout<<"No\n";
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}