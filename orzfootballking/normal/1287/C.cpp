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
int a[105],n,o1,o2,af[105];
int p[105][55][55][2];
int dfs(int e,int x,int y,int last){
	if(p[e][x][y][last]!=-1)return p[e][x][y][last];
	if(e==n+1){
		return p[e][x][y][last]=0;
	}
	if(af[e]){
		return p[e][x][y][last]=(a[e]^last)+dfs(e+1,x,y,a[e]);
	}else{
		int re=2147483647;
		if(x<o1){
			re=min(re,(1^last)+dfs(e+1,x+1,y,1));
		}
		if(y<o2){
			re=min(re,(0^last)+dfs(e+1,x,y+1,0));
		}
		return p[e][x][y][last]=re;
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    memset(p,-1,sizeof(p));
	int x;
	cin>>n;
	o1=(n+1)>>1;
	o2=n-o1;
	FOR(i,1,n){
		cin>>a[i];
		if(a[i]==0)continue;
		if(a[i]&1){
			o1--;
		}else o2--;
		a[i]%=2;af[i]=1;
	}
	if(af[1]){
		cout<<dfs(2,0,0,a[1]);
	}else{
		if(!o1){
			cout<<dfs(2,0,1,0);return 0;
		}else if(!o2){
			cout<<dfs(2,1,0,1);return 0;
		}
		cout<<min(dfs(2,1,0,1),dfs(2,0,1,0));
	}
	return 0;
}