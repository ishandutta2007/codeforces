#include<bits/stdc++.h>
#define int long long
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
int n,k,mod=998244353,cnt;
int ch[150005*32][2],siz[150005*32],root;
void update(int &x,int to,int k){
	if(!x)x=++cnt;
	siz[x]++;
	if(k==-1)RE ;
	if(to&(1<<k))update(ch[x][1],to,k-1);
	else update(ch[x][0],to,k-1);
}
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int p2[150005];
int solve(int x,int y,int to,int k){
	if(!x||!y)RE p2[siz[x]+siz[y]]-1;
	if(k==-1){
		RE p2[siz[x]+siz[y]]-1;
	}
	if(to&(1<<k)){
		RE (solve(ch[x][0],ch[y][1],to,k-1)+1)*(solve(ch[x][1],ch[y][0],to,k-1)+1)%mod-1;
	}else {
		RE (solve(ch[x][0],ch[y][0],to,k-1)+solve(ch[x][1],ch[y][1],to,k-1)+
		(p2[siz[ch[x][0]]]-1)*(p2[siz[ch[x][1]]]-1)+(p2[siz[ch[y][0]]]-1)*(p2[siz[ch[y][1]]]-1))%mod;
	}
}
int solve(int x,int to,int k){
	if(!x)RE 0;
	if(k==-1){
		RE p2[siz[x]]-1;
	}
	if(to&(1<<k)){
		int t=solve(ch[x][0],ch[x][1],to,k-1);
//		cout<<siz[x]<<' '<<t<<'\n';
		RE t;
	}else RE(solve(ch[x][0],to,k-1)+solve(ch[x][1],to,k-1))%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	p2[0]=1;
	FOR(i,1,n){
		p2[i]=p2[i-1]*2%mod;
	}
	FOR(i,1,n){
		int x;
		cin>>x;
		update(root,x,29);
	}
	cout<<solve(root,k,29);
	RE 0;
}