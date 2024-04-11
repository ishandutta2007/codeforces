/*

DP





ll int
 dp 










*/
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
char c[100005];
int x,ans[100005];
void solve(){
	scanf("%s%d",c+1,&x);
	int n=strlen(c+1);
	FOR(i,1,n){
		ans[i]=0;
	}
//	cout<<n<<'\n';
	FOR(i,1,n){
		if(c[i]=='0'){
			if(i>x){
				if(ans[i-x]==1){
					cout<<-1<<'\n';RE ;
				}
				ans[i-x]=2;
			}
			if(i+x<=n){
				if(ans[i+x]==1){
					cout<<-1<<'\n';RE;
				}
				ans[i+x]=2;
			}
		}else{
			if(i>x&&ans[i-x]!=2){
				ans[i-x]=1;
			}else{
				if(i+x>n){
					cout<<-1<<'\n';RE;
				}
				ans[i+x]=1;
			}
		}
	}
	FOR(i,1,n){
		if(ans[i]==1){
			cout<<1;
		}else cout<<0;
	} 
	cout<<'\n';
}
signed main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	RE 0;
}