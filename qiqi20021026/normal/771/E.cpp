#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

#define N 800000
#define LL long long
#define INF 0x3f3f3f3f

int n,tot,nxt[3][N],f[N],head[N],go[N*15];
LL a[3][N];
map<LL,int> m[3];
struct node{int x,y,val;}q[N*15];

void upd(int x,int y,int val){
	int mx=max(x,y),mn=min(x,y);
	f[mx]=max(f[mx],val);
	q[++tot]=(node){x,y,val}; go[tot]=head[mn]; head[mn]=tot;
}

void add(int x,int y,int val){
	if (x<n){
		upd(x+1,y,val);
		if (nxt[1][x]!=0) upd(nxt[1][x],y,val+1);
	}
	if (y<n){
		upd(x,y+1,val);
		if (nxt[2][y]!=0) upd(x,nxt[2][y],val+1);
	}
	if (x<n && x==y && nxt[0][x]!=0) upd(nxt[0][x],nxt[0][x],val+1);
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){scanf("%lld",&a[1][i]); a[1][i]+=a[1][i-1]; a[0][i]+=a[1][i];}
	for (int i=1;i<=n;i++){scanf("%lld",&a[2][i]); a[2][i]+=a[2][i-1]; a[0][i]+=a[2][i];}
	for (int i=n;i>=0;i--){
		if (m[0][a[0][i]]) nxt[0][i]=m[0][a[0][i]];
		if (m[1][a[1][i]]) nxt[1][i]=m[1][a[1][i]];
		if (m[2][a[2][i]]) nxt[2][i]=m[2][a[2][i]];
		m[0][a[0][i]]=i;
		m[1][a[1][i]]=i;
		m[2][a[2][i]]=i;
	}
	for (int i=0;i<=n;i++){
		int now=f[i],x=INF,y=INF; add(i,i,now);
		for (int j=head[i];j;j=go[j]){
			if (q[j].x==i && q[j].val==now+1) y=min(y,q[j].y);
			if (q[j].y==i && q[j].val==now+1) x=min(x,q[j].x);
		}
		if (x!=INF) add(x,i,now+1);
		if (y!=INF) add(i,y,now+1);
	}
	printf("%d\n",f[n]);
	
	return 0;
}