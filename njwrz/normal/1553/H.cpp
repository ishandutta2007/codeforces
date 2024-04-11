#pragma GCC optimize(2)
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
const int maxn=(1<<19)+5;
int ch[maxn<<1][2],maxi[maxn<<1],mini[maxn<<1],ans[maxn<<1];
int k;
int out[maxn],cnt;
void update(int &x,int l,int r,int iter){
	if(!x)x=++cnt;
	if(l==r){
		maxi[x]=mini[x]=0;ans[x]=1e9;
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=iter)update(ch[x][0],l,mid,iter);
	else update(ch[x][1],mid+1,r,iter);
	maxi[x]=max(maxi[ch[x][0]],maxi[ch[x][1]]+(mid-l+1));
	mini[x]=min(mini[ch[x][0]],mini[ch[x][1]]+(mid-l+1));
	ans[x]=min(ans[ch[x][0]],ans[ch[x][1]]);
	gmin(ans[x],mini[ch[x][1]]+(mid-l+1)-maxi[ch[x][0]]);
}
void swap(int x,int l,int r,int to){
	if(!x)RE ;
	int mid=(l+r)>>1;
	if((r-l+1)==(1<<to))swap(ch[x][0],ch[x][1]);
	else{
		swap(ch[x][0],l,mid,to);
		swap(ch[x][1],mid+1,r,to);
	}
	maxi[x]=max(maxi[ch[x][0]],maxi[ch[x][1]]+(mid-l+1));
	mini[x]=min(mini[ch[x][0]],mini[ch[x][1]]+(mid-l+1));
	ans[x]=min(ans[ch[x][0]],ans[ch[x][1]]);
	gmin(ans[x],mini[ch[x][1]]+(mid-l+1)-maxi[ch[x][0]]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n>>k;
	mini[0]=1e9;maxi[0]=-1e9;ans[0]=1e9;
	int root=0,m=(1<<k)-1;
	FOR(i,1,n){
		int x;
		cin>>x;
		update(root,0,m,x);
	}
	cout<<ans[root]<<' ';
	int lst=0;
	FOR(x,1,m){
		int to=0;
		rep(j,0,k)if(x&(1<<j))to^=1<<(k-j-1);
		rep(j,0,k)if((lst&(1<<j))!=(to&(1<<j))){
			swap(root,0,m,j+1);
		}
		out[to]=ans[root];
		lst=to;
	}
	FOR(i,1,m)cout<<out[i]<<' ';
	RE 0;
}