#include<bits/stdc++.h>
#define int long long
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
int a[200005];
void solve(){
	int n;
	cin>>n;
	int x,s=0,maxi=0,sum=0;
	FOR(i,1,n)cin>>a[i],sum+=a[i];
	FOR(i,1,n-1){
		s+=a[i];
		if(s<0)s=0;
		maxi=max(maxi,s);
	}
	s=0;
	FOR(i,2,n){
		s+=a[i];
		if(s<0)s=0;
		maxi=max(maxi,s);
	}
	if(sum<=maxi)cout<<"NO";else cout<<"YES";
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}