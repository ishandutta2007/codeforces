#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=50+5,maxm=100+5,maxt=2e4+5;
int n,m,t,x,a[maxm],b[maxm],c[maxm],p[maxm][maxt];
struct edge{
	int v,w;
};
vector<edge> g[maxn];
typedef pair<int,int> pii;
int d[maxn];
const int inf=2e9;
void dj(){
	for(int i=1;i<n;i++) d[i]=inf;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,n});
	while(pq.size()){
		int u=pq.top().second;
		if(pq.top().first>d[u]){
			pq.pop();
			continue;
		}
		pq.pop();
		for(edge e:g[u]) if(d[e.v]>d[u]+e.w){
			d[e.v]=d[u]+e.w;
			pq.push({d[e.v],e.v});
		}
	}
}
struct cp{
	double re=0,im=0;
	cp operator +(cp b){
		return {re+b.re,im+b.im};
	}
	cp operator -(cp b){
		return {re-b.re,im-b.im};
	}
	cp operator *(cp b){
		return {re*b.re-im*b.im,re*b.im+im*b.re};
	}
};
typedef vector<cp> poly;
int rev[maxt*6];
cp w[maxt*6],w2[maxt*6];
const double pi=acos(-1);
void init(int n){
    for(int i=1;i<n;i++) rev[i]=rev[i>>1]>>1|((i&1)?n>>1:0);
    for(int i=1;i<n;i*=2){
        w[i]={1,0};
        cp wn={cos(pi/i),sin(pi/i)};
        for(int j=1;j<i;j++) w[i+j]=w[i+j-1]*wn;
    }
    for(int i=1;i<n;i*=2){
        w2[i]={1,0};
        cp wn={cos(pi/i),-sin(pi/i)};
        for(int j=1;j<i;j++) w2[i+j]=w2[i+j-1]*wn;
    }
}
poly FFT(poly F,bool flag){
    int n=F.size();
    for(int i=0;i<n;i++) if(i<rev[i]) swap(F[i],F[rev[i]]);
    for(int i=1;i<n;i*=2) for(int j=0;j<n;j+=i*2)
        for(int k=j;k<j+i;k++){
            cp t=F[k+i]*(flag?w[i+k-j]:w2[i+k-j]);
            F[k+i]=F[k]-t;
            F[k]=F[k]+t;
        }
    if(!flag) for(int i=0;i<n;i++){
		F[i].re/=n;
		F[i].im/=n;
	}
    return F;
}
double f[maxn][maxt*2],h[maxm][maxt*2];
void solve(int l,int r){
	if(l>t) return;
	if(l==r){
		for(int i=1;i<n;i++) f[i][r]=1.0/0.0;
		for(int i=1;i<=m;i++) f[a[i]][r]=min(f[a[i]][r],h[i][r]+c[i]);
		return;
	}
	int mid=l+(r-l)/2;
	solve(mid+1,r);
	int len=1;
	while(len<r*2-mid-l) len*=2;
	init(len);
	for(int i=1;i<=m;i++){
		poly F(r-mid),G(r-l);
		for(int j=mid+1;j<=r;j++) F[j-mid-1]={f[b[i]][j],0};
		for(int j=1;j<=min(r-l,t);j++) G[r-l-j]={p[i][j]/1e5,0};
		F.resize(len);
		G.resize(len);
		F=FFT(F,1);
		G=FFT(G,1);
		for(int j=0;j<len;j++) F[j]=F[j]*G[j];
		F=FFT(F,0);
		for(int j=l;j<=mid;j++) h[i][j]+=F[j-mid+r-l-1].re;
	}
	solve(l,mid);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	t=readint();
	x=readint();
	for(int i=1;i<=m;i++){
		a[i]=readint();
		b[i]=readint();
		c[i]=readint();
		g[b[i]].push_back({a[i],c[i]});
		for(int j=1;j<=t;j++) p[i][j]=readint();
	}
	dj();
	for(int i=1;i<=n;i++) for(int j=t+1;j<=t*2;j++) f[i][j]=d[i]+x;
	solve(0,t*2);
	printf("%.10f\n",f[1][0]);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}