#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
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
int a[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,s=0;
	cin>>n;
	FOR(i,1,n)cin>>a[i],s+=a[i];
	sort(a+1,a+n+1,greater<int>());
	int sum=0;
	FOR(i,1,(n+1)/2)sum+=a[i];
	s=s-sum;
	cout<<s*s+sum*sum;
	RE 0;
}