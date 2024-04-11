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
	int a,b,c,n;
	cin>>a>>b>>c>>n;
	int t=max(max(a,b),c);
	n-=t-a;n-=t-b;n-=t-c;
	if(n>=0&&n%3==0)cout<<"YES\n";else cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}