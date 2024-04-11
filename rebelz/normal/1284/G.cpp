#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int q[1005][2],col[405],f[1005],du[405];
pii e[1005];
char s[25][25],ts[405];
vector<int> g[1005],st,ed;
bool ans[1005],vis[1005];

void init(){
	memset(col,0,sizeof(col));
	memset(du,0,sizeof(du));
	memset(e,0,sizeof(e));
	memset(ans,0,sizeof(ans));
}

int id(int i,int j,int k){return i==0?(j-1)*(m+1)+k:(j-1)*m+k+n*(m+1);}
int id1(int i,int j){return i<1||i>n||j<1||j>m?0:(i-1)*m+j;}
int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

bool merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy) return false;
	f[fx]=fy;
	return true;
}

bool bfs(){
	int front=0,rear=0;
	q[rear][0]=0,q[rear++][1]=-1;
	while(front<rear){
		int t=q[front][0],pre=q[front++][1];
		if(t==id(1,n+1,m)+1){
			while(pre>=0){
				ans[q[pre][0]]^=1;
				pre=q[pre][1];
			}
			return true;
		}
		for(auto v:g[t]){
			if(vis[v]) continue;
			vis[v]=true;
			q[rear][0]=v,q[rear++][1]=front-1;
		}
	}
	return false;
}

int main(){
	int T=readint();
	while(T--){
		init();
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ts[id1(i,j)]=s[i][j];
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) col[id1(i,j)]=(i+j)&1;
		col[id1(1,1)]=1;
		for(int i=1;i<=n;i++) for(int j=2;j<=m;j++) e[id(0,i,j)]=mp(id1(i,j-1),id1(i,j));
		for(int i=2;i<=n;i++) for(int j=1;j<=m;j++) e[id(1,i,j)]=mp(id1(i-1,j),id1(i,j));
		for(int i=1;i<=n;i++) ans[id(0,i,1)]=ans[id(0,i,m+1)]=1;
		for(int i=1;i<=m;i++) ans[id(1,1,i)]=ans[id(1,n+1,i)]=1;
		int badnum=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s[i][j]=='X')
					ans[id(0,i,j)]=ans[id(0,i,j+1)]=ans[id(1,i,j)]=ans[id(1,i+1,j)]=1,badnum++;
		for(int i=1;i<=n;i++) for(int j=1;j<=m+1;j++) if(ans[id(0,i,j)]) du[id1(i,j-1)]++,du[id1(i,j)]++;
		for(int i=1;i<=n+1;i++) for(int j=1;j<=m;j++) if(ans[id(1,i,j)]) du[id1(i-1,j)]++,du[id1(i,j)]++;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) f[id1(i,j)]=id1(i,j);
		for(int i=1;i<=id(1,n+1,m);i++) if(e[i].fi&&!ans[i]) merge(e[i].fi,e[i].se);
		bool fl=0;
		for(int i=1;i<=id1(n,m);i++) if(ts[i]=='O'&&getf(i)!=getf(1)) fl=1;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if((i!=1||j!=1)&&s[i][j]=='O'&&du[id1(i,j)]>col[id1(i,j)]+2) fl=1;
		if(fl){
			printf("NO\n");
			continue;
		}
		while(1){
			memset(du,0,sizeof(du));
			for(int i=1;i<=n;i++) for(int j=1;j<=m+1;j++) if(ans[id(0,i,j)]) du[id1(i,j-1)]++,du[id1(i,j)]++;
			for(int i=1;i<=n+1;i++) for(int j=1;j<=m;j++) if(ans[id(1,i,j)]) du[id1(i-1,j)]++,du[id1(i,j)]++;
			for(int i=0;i<=id(1,n+1,m);i++) g[i].clear();
			st.clear(),ed.clear();
			for(int i=1;i<=id(1,n+1,m);i++){
				if(!e[i].fi) continue;
				if(ans[i]) st.push_back(i);
				else ed.push_back(i);
			}
			for(auto i:ed){
				if((ts[e[i].fi]=='X'||du[e[i].fi]+1<=col[e[i].fi]+2)
					&&(ts[e[i].se]=='X'||du[e[i].se]+1<=col[e[i].se]+2)) g[i].push_back(id(1,n+1,m)+1);
			}
			for(auto i:ed){
				for(auto j:st){
					if(!e[j].fi) continue;
					if((ts[e[i].fi]=='X'||du[e[i].fi]+1-(e[j].fi==e[i].fi||e[j].se==e[i].fi)<=col[e[i].fi]+2)
						&&(ts[e[i].se]=='X'||du[e[i].se]+1-(e[j].fi==e[i].se||e[j].se==e[i].se)<=col[e[i].se]+2)) g[i].push_back(j);
				}
				for(int j=1;j<=id1(n,m);j++) f[j]=j;
				int cnt=0;
				for(auto j:ed){
					if(j!=i&&e[j].fi&&merge(e[j].fi,e[j].se)) cnt++;
					if(cnt==id1(n,m)-badnum-1) break;
				}
				cnt=id1(n,m)-badnum-cnt;
				if(cnt==1) g[0].push_back(i);
				if(cnt>2) break;
				for(auto j:st){
					if(ts[e[j].fi]=='X'||ts[e[j].se]=='X') continue;
					int fx=getf(e[j].fi),fy=getf(e[j].se);
					if(fx==fy&&cnt==1) g[j].push_back(i);
					else if(fx!=fy&&cnt==2) g[j].push_back(i);
				}
			}
			memset(vis,0,sizeof(vis));
			vis[0]=1;
			if(!bfs()) break;
		}
		bool fl1=0;
		for(int i=1;i<=id1(n,m);i++) f[i]=i;
		for(int i=1;i<=id(1,n+1,m);i++) if(e[i].fi&&!ans[i]&&!merge(e[i].fi,e[i].se)) fl1=1;
		if(fl1){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=2*n-1;i++){
			for(int j=1;j<=2*m-1;j++){
				if((i&1)&&(j&1)) printf("%c",s[(i+1)/2][(j+1)/2]);
				else if((i&1)&&!(j&1)) printf("%c",ans[id(0,(i+1)/2,j/2+1)]?' ':'O');
				else if(!(i&1)&&(j&1)) printf("%c",ans[id(1,i/2+1,(j+1)/2)]?' ':'O');
				else printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}