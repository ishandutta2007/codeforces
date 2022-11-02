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
char c[200005];
void solve(){
	scanf("%s",c+1);
	int ans=1e9,n=strlen(c+1);
	FOR(i,0,9){
		int cnt=0;
		FOR(j,1,n){
			cnt+=c[j]==(i+'0');
		} 
		gmin(ans,n-cnt);
	}
	FOR(i,0,9){
		FOR(j,0,9){
			if(i==j)continue;
			int cnt=0,now=i;
			FOR(p,1,n){
				if(c[p]==now+'0'){
					cnt++;
					now=now^i^j;
				}
			}
			cnt/=2;
			cnt*=2;
			gmin(ans,n-cnt);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	RE 0;
}