#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct edge{
	int x,y,z;
	bool operator<(const edge c)const{return z<c.z;}
}e[155];

int n,m,tot;
int v[155],nxt[155],h[155],d[155],q[155];

struct matrix{
	bitset<155> a[155],b[155];
	matrix(){for(int i=1;i<=n;i++) a[i].reset(),b[i].reset();}
	matrix operator*(const matrix c)const{
		matrix ret;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ret.a[i][j]=ret.b[j][i]=(a[i]&c.b[j]).any();
		return ret;
	}
}ans,now;

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

matrix qpow(matrix x,int p){
	matrix ret;
	for(int i=1;i<=n;i++) ret.a[i][i]=ret.b[i][i]=1;
	for(;p;p>>=1,x=x*x) if(p&1) ret=ret*x;
	return ret;
}

int bfs(int x){
	memset(d,0x3f,sizeof(d));
	int front=0,rear=0;
	q[rear++]=x,d[x]=0;
	while(front<rear){
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p]){
			if(d[v[p]]<=n) continue;
			d[v[p]]=d[t]+1;
			q[rear++]=v[p];
		}
	}
	if(d[n]>n) return -1;
	return d[n];
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) e[i].x=readint(),e[i].y=readint(),e[i].z=readint();
	sort(e+1,e+m+1);
	matrix now;
	ans.a[1][1]=ans.b[1][1]=1;
	int res=1<<30;
	for(int i=1;i<=m;i++){
		ans=ans*qpow(now,e[i].z-e[i-1].z);
		now.a[e[i].x][e[i].y]=now.b[e[i].y][e[i].x]=1;
		addedge(e[i].x,e[i].y);
		for(int j=1;j<=n;j++){
			if(!ans.a[1][j]) continue;
			int tmp=bfs(j);
			if(tmp>=0) chkmin(res,e[i].z+tmp);
		}
	}
	if(res<(1<<30)) printf("%lld\n",res);
	else printf("Impossible\n");
	return 0;
}