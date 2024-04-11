#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,a,b,tot;
int v[2005],nxt[2005],h[2005];
double d[505][505],ans[505],du[505],k[505];

int id(int x,int y){return (x-1)*n+y;}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot; du[y]++;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot; du[x]++;
}

void gauss(){
	int p;
	for(int i=1;i<=n*n;i++){
		p=i;
		for(int j=i+1;j<=n*n;j++) if(fabs(d[j][i])>fabs(d[p][i])) p=j;
		for(int j=i;j<=n*n+1;j++) swap(d[i][j],d[p][j]);
		for(int j=i+1;j<=n*n;j++){
			double tmp=d[j][i]/d[i][i];
			for(int k=i;k<=n*n+1;k++) d[j][k]-=d[i][k]*tmp;
		}
	}
	for(int i=n*n;i>=1;i--){
		for(int j=i+1;j<=n*n;j++) d[i][n*n+1]-=ans[j]*d[i][j];
		ans[i]=d[i][n*n+1]/d[i][i];
	}
}

int main(){
	n=readint(); m=readint(); a=readint(); b=readint();
	d[id(a,b)][n*n+1]--;
	for(int i=1;i<=m;i++) addedge(readint(),readint());
	for(int i=1;i<=n;i++) scanf("%lf",&k[i]);
	for(int i=1;i<=n*n;i++){
		int x=(i-1)/n+1,y=(i-1)%n+1;
		d[i][i]--;
		if(x!=y) d[i][i]+=k[x]*k[y];
		for(int p1=h[x];p1;p1=nxt[p1])
			for(int p2=h[y];p2;p2=nxt[p2])
				if(v[p1]!=v[p2]) d[i][id(v[p1],v[p2])]+=1.0*(1-k[v[p1]])/du[v[p1]]*(1-k[v[p2]])/du[v[p2]];
		for(int p=h[x];p;p=nxt[p]) if(v[p]!=y) d[i][id(v[p],y)]+=1.0*(1-k[v[p]])/du[v[p]]*k[y];
		for(int p=h[y];p;p=nxt[p]) if(x!=v[p]) d[i][id(x,v[p])]+=1.0*k[x]*(1-k[v[p]])/du[v[p]];
	}
//	for(int i=1;i<=n*n;i++){
//		for(int j=1;j<=n*n+1;j++) cout<<d[i][j]<<' ';
//		cout<<endl;
//	}
	gauss();
	for(int i=1;i<=n;i++) printf("%.6lf ",ans[id(i,i)]);
	printf("\n");
	return 0;
}