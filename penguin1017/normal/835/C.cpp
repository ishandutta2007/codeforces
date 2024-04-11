#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=100+9;
const ll mod=998244353;
int pos[11][N][N]; 
int main(){
	int n,q,c;
	scanf("%d%d%d",&n,&q,&c);
	++c;
	rep(i,0,n){
		int x,y,s;
		scanf("%d%d%d",&x,&y,&s);
		pos[0][x][y]+=s;
		rep(id,1,c)s=(s+1)%c,pos[id][x][y]+=s;
	}
	rep(id,0,c){
		rep(i,1,101){
			rep(j,1,101){
				pos[id][i][j]=-pos[id][i-1][j-1]+pos[id][i][j-1]+pos[id][i-1][j]+pos[id][i][j];
			}
		}
	}
	while(q--){
		int xl,yl,xr,yr,t;
		scanf("%d%d%d%d%d",&t,&xl,&yl,&xr,&yr);
		--xl,--yl;
		t%=c;
		printf("%d\n",pos[t][xl][yl]+pos[t][xr][yr]-pos[t][xl][yr]-pos[t][xr][yl]);
	}
}
/*
3 5 5
1 1 2
2 3 0
3 3 1
0 1 1 100 100
1 2 2 4 4
2 2 1 4 7
1 50 50 51 51
14 2 1 4 7
*/