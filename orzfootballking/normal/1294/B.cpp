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
P<int,int> p[1005];int n;
void solve(){
	cin>>n;
	FOR(i,1,n){
		cin>>p[i].F>>p[i].S;
	}
	sort(p+1,p+n+1);
	FOR(i,2,n){
		if(p[i].S<p[i-1].S){
			cout<<"NO\n";return ;
		}
	}
	int x,y;x=y=0;
	cout<<"YES\n";
	FOR(i,1,n){
		for(int j=x+1;j<=p[i].F;j++)cout<<'R';
		for(int j=y+1;j<=p[i].S;j++)cout<<'U';
		x=p[i].F;y=p[i].S;
	}
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