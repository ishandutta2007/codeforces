// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot;
int v[600005],c[600005],nxt[600005],h[200005],dis[200005],a[200005],lst[200005];

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
}

void bfs(){
	for(int i=2;i<=n;i++) dis[i]=n+1;
	queue<int> q1,q2;
	q1.push(1);
	while(!q1.empty()||!q2.empty()){
		int t;
		if(!q2.empty()) t=q2.front(),q2.pop();
		else t=q1.front(),q1.pop();
		for(int p=h[t];p;p=nxt[p]){
			if(chkmin(dis[v[p]],dis[t]+c[p])){
				if(!c[p]) q2.push(v[p]);
				else q1.push(v[p]);
			}
		}
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) lst[a[i]]=i;
	for(int i=1;i<n;i++) addedge(i,i+1,1);
	for(int i=1;i<=n;i++) if(i!=lst[a[i]]) addedge(i,lst[a[i]],1);
	for(int i=1;i<n;i++) addedge(i+1,i,0);
	bfs();
	printf("%d\n",n-dis[n]-1);
	return 0;
}