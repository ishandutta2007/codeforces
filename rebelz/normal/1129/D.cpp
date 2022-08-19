#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,k,cnt,block;
int a[100005],st[1005],en[1005],bl[100005],sum[100005],lazy[1005],pre[100005],lst[100005];
pii t[100005],b[100005];

int mod(int x){return x>=cys?x-cys:x;}

void init(){
	block=sqrt(n);
	for(int i=1;i<=n;i+=block) st[++cnt]=i,en[cnt]=i+block-1;
	en[cnt]=n;
	for(int i=1;i<=cnt;i++) for(int j=st[i];j<=en[i];j++) bl[j]=i;
}

void add(int l,int r,int c){
	int lb=bl[l],rb=bl[r];
	if(lb==rb){
		for(int i=l;i<=r;i++) t[i].fi+=c;
		for(int i=st[lb];i<=en[lb];i++) b[i]=t[i];
		sort(b+st[lb],b+en[lb]+1);
		sum[st[lb]]=b[st[lb]].se;
		for(int i=st[lb]+1;i<=en[lb];i++) sum[i]=mod(sum[i-1]+b[i].se);
		return;
	}
	for(int i=l;i<=en[lb];i++) t[i].fi+=c;
	for(int i=st[rb];i<=r;i++) t[i].fi+=c;
	for(int i=st[lb];i<=en[lb];i++) b[i]=t[i];
	sort(b+st[lb],b+en[lb]+1);
	sum[st[lb]]=b[st[lb]].se;
	for(int i=st[lb]+1;i<=en[lb];i++) sum[i]=mod(sum[i-1]+b[i].se);
	for(int i=st[rb];i<=en[rb];i++) b[i]=t[i];
	sort(b+st[rb],b+en[rb]+1);
	sum[st[rb]]=b[st[rb]].se;
	for(int i=st[rb]+1;i<=en[rb];i++) sum[i]=mod(sum[i-1]+b[i].se);
	for(int i=lb+1;i<=rb-1;i++) lazy[i]+=c;
}

int ask(int x){
	int rb=bl[x],ret=0;
	for(int i=st[rb];i<=x;i++) if(t[i].fi+lazy[rb]<=k) ret=mod(ret+t[i].se);
	for(int i=1;i<=rb-1;i++) if(b[st[i]].fi+lazy[i]<=k) ret=mod(ret+sum[upper_bound(b+st[i],b+en[i]+1,mp(k-lazy[i],1<<30))-b-1]);
//	cout<<"TEST "<<x<<' '<<ret<<endl;
	return ret;
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++){
		pre[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	init();
	t[1].se=1;
	for(int i=1;i<=n;i++){
		add(pre[i]+1,i,1);
		if(pre[i]) add(pre[pre[i]]+1,pre[i],-1);
		t[i+1].se=ask(i);
		if((i+1)%block==0){
			for(int j=i-block+2;j<=i+1;j++) b[i]=t[i];
			sort(b+i-block+2,b+i+2);
			sum[i-block+2]=b[i-block+2].se;
			for(int j=i-block+3;j<=i+1;j++) sum[j]=mod(sum[j-1]+b[j].se);
		}
	}
	printf("%d\n",t[n+1].se);
	return 0;
}