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
	int n,d;
	cin>>n>>d;
	int t=sqrt(d);
	int ans=min(t+d/(t+1)+(d%(t+1)!=0),t-1+d/t+(d%t!=0));
	if(ans>n){
		cout<<"NO\n";
	}else cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}