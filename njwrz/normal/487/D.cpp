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
int n,m,q;
char c[100005][12];
P<int,int> to[100005][12];
int B=300;
void solve(int x){
	int l=(x-1)*B+1;
	FOR(i,l,min(n,x*B)){
		FOR(j,2,m){
			if(c[i][j-1]=='>'&&c[i][j]=='<')to[i][j]=to[i][j-1]=MP(-1,-1);
		}
		FOR(j,1,m){
			if(c[i][j]=='^'){
				if(i>l)to[i][j]=to[i-1][j];
				else to[i][j]=MP(i-1,j);
			}else if(c[i][j]=='<'){
				to[i][j]=to[i][j-1];
			}
		}
		for(int j=m;j>=1;j--){
			if(c[i][j]=='>'){
				to[i][j]=to[i][j+1];
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>c[i][j];
		}
	}
	FOR(i,1,m)to[0][i]=MP(0,i);
	FOR(i,1,n)to[i][0]=MP(i,0),to[i][m+1]=MP(i,m+1);
	FOR(i,1,(n+B-1)/B)solve(i);
	FOR(i,1,q){
		char tap;
		cin>>tap;
		int x,y;
		char ch;
		if(tap=='C'){
			cin>>x>>y>>ch;c[x][y]=ch;
			solve((x+B-1)/B);
		}else {
			cin>>x>>y;
			P<int,int> ans=MP(x,y);
			while(1){
				ans=to[ans.F][ans.S];
				if(ans.F<1||ans.S>m||ans.S<1){
					break;
				}
			}
			cout<<ans.F<<' '<<ans.S<<'\n';
		}
	}
	RE 0;
}