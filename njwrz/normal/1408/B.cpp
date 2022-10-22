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
int a[105];
void solve(){
	int n,m;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	int ans=0;
	while(1){
		ans++;
		int cnt=1;
		FOR(i,2,n){
			cnt+=a[i]!=a[i-1];
		}
		if(cnt<=m){
			cout<<ans<<'\n';RE;
		}
		cnt=0;
		FOR(i,1,n){
			cnt+=a[i]!=a[i-1]||i==1;
			if(cnt==m){
				if(!a[i]){
					cout<<-1<<'\n';RE;
				}
				FOR(j,i+1,n)a[j]-=a[i];
				FOR(j,1,i)a[j]=0;
				break;
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}