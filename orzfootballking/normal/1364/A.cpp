#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int a[100005];
void solve(){
	int n,m,sum=0;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i],sum+=a[i];
	if(sum%m!=0){
		cout<<n<<'\n';RE; 
	}
	int l=-1;
	FOR(i,1,n){
		if(a[i]%m!=0){
			l=i;break;
		}
	}
	int r=-1;
	for(int i=n;i>=1;i--)if(a[i]%m!=0){
		r=i;break;
	}
	if(l==-1){
		cout<<-1<<'\n';
	}else {
		cout<<max(n-l,r-1)<<'\n';
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