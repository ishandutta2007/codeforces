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
	ll mina,lazy,sum;
}t[600000];

int n,mx;
vector<int> v[200005];
int a[200005],fl[200005],cnt[200005];
ll d[200005];

void build(int id,int l,int r){
	if(l==r) return (void)(t[id].sum=t[id].mina=l);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id].sum=t[id<<1].sum+t[id<<1|1].sum;
	t[id].mina=min(t[id<<1].mina,t[id<<1|1].mina);
}

void pushdown(int id,int l,int r){
	if(t[id].lazy){
		int mid=(l+r)/2;
		t[id<<1].lazy=t[id<<1].mina=t[id<<1|1].lazy=t[id<<1|1].mina=t[id].lazy;
		t[id<<1].sum=1ll*(mid-l+1)*t[id].lazy,t[id<<1|1].sum=1ll*(r-mid)*t[id].lazy;
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(ql>qr) return;
	if(l==ql&&r==qr){
		t[id].lazy=t[id].mina=c,t[id].sum=1ll*(r-l+1)*c;
		return;
	}
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	t[id].sum=t[id<<1].sum+t[id<<1|1].sum;
	t[id].mina=min(t[id<<1].mina,t[id<<1|1].mina);
}

int find(int id,int l,int r,int x){
	if(l==r) return t[id].mina<=x?l:l-1;
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(t[id<<1|1].mina<=x) return find(id<<1|1,mid+1,r,x);
	else return find(id<<1,l,mid,x);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),fl[a[i]]=i,mx=max(mx,a[i]);
	for(int i=1;i<=mx;i++) for(int j=i;j<=mx;j+=i) if(fl[j]) v[i].push_back(fl[j]);
	for(int i=1;i<=mx;i++) sort(v[i].begin(),v[i].end());
	for(int i=1;i<=mx;i++) cnt[i]=v[i].size();
	build(1,1,n);
	for(int i=mx;i>=1;i--){
		if(cnt[i]<=1){
			d[i]=1ll*n*n-t[1].sum+n;
			continue;
		}
		change(1,1,n,1,min(v[i][0],find(1,1,n,v[i][cnt[i]-2])),v[i][cnt[i]-2]);
		change(1,1,n,v[i][0]+1,min(v[i][1],find(1,1,n,v[i][cnt[i]-1])),v[i][cnt[i]-1]);
		change(1,1,n,v[i][1]+1,n,n+1);
		d[i]=1ll*n*n-t[1].sum+n;
	}
	ll ans=0;
	for(int i=1;i<mx;i++) ans+=1ll*i*(d[i+1]-d[i]);
	cout<<ans<<endl;
	return 0;
}