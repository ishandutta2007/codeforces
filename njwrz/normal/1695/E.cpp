#include<bits/stdc++.h>
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define MP make_pair
#define PB emplace_back
using namespace std;
V<P<int,int>> v[600005];
bool vis[600005];
int siz=0,num[600005],used[300005],len,n;
char c[2][2][300005];
void dfs(int x){
	vis[x]=1;
	siz+=v[x].size();
	for(auto u:v[x]){
		if(!vis[u.F]){
			num[++len]=u.F;used[u.S]=1;dfs(u.F);num[++len]=x;
		}else if(!used[u.S])num[++len]=u.F,num[++len]=x,used[u.S]=1;
	}
}
int a[2][300005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(MP(y,i));
		v[y].PB(MP(x,i));
	}
	int cnt=0;
	FOR(i,1,2*n)if(!vis[i]){
		siz=0;len=0;
		dfs(i);
		siz/=2;
		if(!siz)continue;
		if(siz==1){
			cout<<-1;RE 0;
		}
		for(int j=cnt+1;j<cnt+siz;j+=2)c[0][0][j]=c[0][1][j]='L',c[0][0][j+1]=c[0][1][j+1]='R';
		for(int j=cnt+2;j<cnt+siz;j+=2)c[1][0][j]=c[1][1][j]='L',c[1][0][j+1]=c[1][1][j+1]='R';
		if(siz&1){
			c[0][0][cnt+siz]='U';c[0][1][cnt+siz]='D';
			c[1][0][cnt+1]='U';c[1][1][cnt+1]='D';
		}else{
			c[1][0][cnt+siz]='U';c[1][1][cnt+siz]='D';
			c[1][0][cnt+1]='U';c[1][1][cnt+1]='D';
		}
		int it=0;
		FOR(j,cnt+1,cnt+siz)a[0][j]=num[++it];
		for(int j=cnt+siz;j>cnt;j--)a[1][j]=num[++it];
		cnt+=siz;
	}
	cout<<2<<' '<<n<<'\n'<<'\n';
	rep(i,0,2){
		FOR(j,1,n)cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
	rep(i,0,2){
		FOR(j,1,n)cout<<c[0][i][j];
		cout<<'\n';
	}
	cout<<'\n';
	rep(i,0,2){
		FOR(j,1,n)cout<<c[1][i][j];
		cout<<'\n';
	}
	RE 0;
}