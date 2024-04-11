#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int lazy;
}t[1100000];

int n,tot,cnt;
int nxt[500005],d[500005][20],lg2[500005],h[500005],v[500005],nt[500005],ans[500005],du[500005],out[500005];
pair<int,int> k[500005];
int dl[500005];

bool cmp(int x,int y){
	return dl[x]<dl[y];
}

struct tp{
	int x;
	tp(int xx=0):x(xx){}
	bool operator<(const tp c)const{return dl[x]>dl[c.x];}
};

priority_queue<tp> q;

void pushdown(int id){
	if(t[id].lazy){
		t[id<<1].lazy=t[id<<1|1].lazy=t[id].lazy;
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(ql>qr) return;
	if(l==ql&&r==qr) return (void)(t[id].lazy=c);
	int mid=(l+r)/2;
	pushdown(id);
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
}

int query(int id,int l,int r,int x){
	if(l==r) return t[id].lazy;
	pushdown(id);
	int mid=(l+r)/2;
	if(x<=mid) return query(id<<1,l,mid,x);
	else return query(id<<1|1,mid+1,r,x);
}

void addedge(int x,int y){
	v[++tot]=y; nt[tot]=h[x]; h[x]=tot; du[y]++; out[x]++;
}

int ask(int l,int r){
	int g=lg2[r-l+1];
	return max(d[l][g],d[r-(1<<g)+1][g]);
}

bool addx(int x,int l,int r){
	if(l>r) return true;
	if(ask(l,r)>r+1) return false;
	return true;
}

bool bfs(){
	int front=0,rear=0;
	for(int i=1;i<=n+1;i++){
		dl[i]=i;
		for(int p=h[i];p;p=nt[p]) dl[i]=min(dl[i],dl[v[p]]);
	}
	t[1].lazy=1<<30;
	q.push(tp(n+1));
	int now=n+1;
	while(!q.empty()){
		tp t=q.top(); q.pop();
		ans[t.x]=now--;
		change(1,1,n,t.x+1,nxt[t.x]-1,now+1);
		for(int p=h[t.x];p;p=nt[p]){
			q.push(v[p]);
		}
	}
	for(int i=1;i<=n;i++) if(du[i]==0&&out[i]!=0) q.push(tp(i));
	while(!q.empty()){
		tp t=q.top(); q.pop();
		ans[t.x]=now--;
		change(1,1,n,t.x+1,nxt[t.x]-1,now+1);
		for(int p=h[t.x];p;p=nt[p]){
			q.push(v[p]);
		}
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		if(!ans[i]){
			k[++cnt]=make_pair(query(1,1,n,i)-1,i);
		}
	}
	sort(k+1,k+cnt+1);
	int num=0;
	for(int i=1;i<=cnt;i++){
		ans[k[i].second]=++num;
		if(num>k[i].first) return false;
	}
	return true;
}

int main(){
	int T=readint();
	for(int i=2;i<=500000;i++) lg2[i]=lg2[i>>1]+1;
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) nxt[i]=d[i][0]=readint(); nxt[n+1]=0;
		for(int i=1;(1<<i)<=n;i++) for(int j=1;j+(1<<i)-1<=n;j++) d[j][i]=max(d[j][i-1],d[j+(1<<(i-1))][i-1]);
		bool fl=true;
		for(int i=1;i<=n+1;i++) h[i]=du[i]=out[i]=0; tot=0;
		for(int i=1;i<=n;i++) if(nxt[i]!=-1) fl&=addx(i,i+1,nxt[i]-1),addedge(nxt[i],i);
		if(!fl){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++) ans[i]=0;
		if(!bfs()) printf("-1\n");
		else{
			for(int i=1;i<=n;i++) printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}