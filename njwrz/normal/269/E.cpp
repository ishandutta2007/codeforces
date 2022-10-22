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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int n,m;
V<int> v[400005],v2[400005];
int mp[300][300],cnt[7];
int num[5][100005];
void add1(int x,int y){
	v[x].PB(y);
	v[y].PB(x);
}
void add2(int x,int y){
	v2[x].PB(y);
	v2[y].PB(x);
}
map<P<int,int>,V<V<int> > > mp2;
int to1[100005],to2[100005];
int vis[400005];
V<int> nownode,node2;
void dfs(int x,V<int> *g){
	node2.PB(x);
	if(x<=n)nownode.PB(1);else if(x<=2*n)nownode.PB(2);else if(x<=2*n+m)nownode.PB(3);else nownode.PB(4);
	vis[x]=1;
	for(auto u:g[x])if(!vis[u])dfs(u,g);
}
int a[400005];
int len;
int getmin(){
	int k=0,i=0,j=1;
	while(k<len&&i<len&&j<len){
	  if(a[(i+k)%len]==a[(j+k)%len]){
	    k++;
	  }else{
	    a[(i+k)%len]>a[(j+k)%len]?i=i+k+1:j=j+k+1;
	    if(i==j)i++;
	    k=0;
	  }
	}
	i=min(i,j);
	RE i;
}
const int B=37,mod=998244353;
V<P<int,V<int> > > get(V<int> *g){
	V<P<int,V<int> > > re;
	FILL(vis,0);
	FOR(i,1,2*(n+m))if(!vis[i]){
		nownode.clear();node2.clear();
		dfs(i,g);
		len=0;
		for(auto u:nownode)a[len++]=u;
		int st=getmin();
		V<int> hav,hav2;
		rep(j,0,len)hav.PB(a[(st+j)%len]),hav2.PB(node2[(st+j)%len]);
		reverse(a,a+len);reverse(ALL(node2));
		st=getmin();
		V<int> newhav;
		rep(j,0,len)newhav.PB(a[(st+j)%len]);
		if(hav>newhav){
			hav=newhav;
			hav2.clear();
			rep(j,0,len)hav2.PB(node2[(st+j)%len]);
		}
		int nowval=0;
		for(auto u:hav)nowval=(1ll*nowval*B+u)%mod;
		re.PB(MP(nowval,hav2));
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	mp['L']['T']=1;mp['T']['L']=1;
	mp['L']['B']=2;mp['B']['L']=2;
	mp['R']['T']=3;mp['T']['R']=3;
	mp['R']['B']=4;mp['B']['R']=4;
	mp['L']['R']=5;mp['R']['L']=5;
	mp['B']['T']=6;mp['T']['B']=6;
	FOR(i,1,100000)num[1][i]=i,num[2][i]=n+i,num[3][i]=2*n+i,num[4][i]=2*n+m+i;
	FOR(i,1,n+m){
		char c1,c2;
		int x1,x2;
		cin>>c1>>c2>>x1>>x2;
		int num1=0,num2=0;
		if(c1=='L')num1=x1;else if(c1=='R')num1=x1+n;else if(c1=='B')num1=x1+2*n;else num1=x1+2*n+m;
		if(c2=='L')num2=x2;else if(c2=='R')num2=x2+n;else if(c2=='B')num2=x2+2*n;else num2=x2+2*n+m;
		int now=mp[c1][c2];
		add1(num1,num2);
		cnt[now]++;
	}
	if(cnt[5]&&cnt[6]){
		cout<<"No solution";RE 0;
	}
	FOR(i,1,n)add1(num[1][i],num[2][i]),add2(num[1][i],num[2][i]);
	FOR(i,1,m)add1(num[3][i],num[4][i]),add2(num[3][i],num[4][i]);
	FOR(i,1,cnt[1])add2(num[1][i],num[4][i]);
	FOR(i,1,cnt[2])add2(num[1][n-i+1],num[3][i]);
	FOR(i,1,cnt[3])add2(num[2][i],num[4][m-i+1]);
	FOR(i,1,cnt[4])add2(num[2][n-i+1],num[3][m-i+1]);
	FOR(i,1,cnt[5])add2(num[1][cnt[1]+i],num[2][cnt[3]+i]);
	FOR(i,1,cnt[6])add2(num[3][cnt[2]+i],num[4][cnt[1]+i]);
	V<P<int,V<int> > > val1=get(v),val2=get(v2);
	for(auto u:val1){
		mp2[MP(u.F,sz(u.S))].PB(u.S);
	}
	for(auto u:val2){
		P<int,int> now=MP(u.F,sz(u.S));
		if(!mp2.count(now)||mp2[now].empty()){
			cout<<"No solution";RE 0;
		}
		V<int> node=mp2[now].back();
		mp2[now].pop_back();
		rep(i,0,sz(u.S)){
			if(u.S[i]<=n)to1[u.S[i]]=node[i];
			else if(u.S[i]>2*n&&u.S[i]<=2*n+m)to2[u.S[i]-2*n]=node[i]-2*n;
		}
	}
	FOR(i,1,n)cout<<to1[i]<<' ';
	cout<<'\n';
	FOR(i,1,m)cout<<to2[i]<<' ';
	RE 0;
}