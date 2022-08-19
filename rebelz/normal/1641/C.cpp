// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
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

int n,q;
int f[200005],x[200005],y[200005],col[200005],sum[600000],hv[200005];
vector<int> vec[600000];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void find(int id,int l,int r,int ql,int qr){
	if(sum[id]==r-l+1) return;
	if(l==r) return (void)(col[l]=1);
	int mid=(l+r)/2;
	if(qr<=mid) find(id<<1,l,mid,ql,qr);
	else if(ql>mid) find(id<<1|1,mid+1,r,ql,qr);
	else find(id<<1,l,mid,ql,mid),find(id<<1|1,mid+1,r,mid+1,qr);
}

void add(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr){
		vec[id].pb(c);
		if(sum[id]==r-l+1) hv[c]-=sum[id];
		else if(sum[id]==r-l) hv[c]-=sum[id];
		return;
	}
	int mid=(l+r)/2;
	if(qr<=mid) add(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) add(id<<1|1,mid+1,r,ql,qr,c);
	else add(id<<1,l,mid,ql,mid,c),add(id<<1|1,mid+1,r,mid+1,qr,c);
}

void del(int id,int l,int r,int p){
	sum[id]++;
	if(sum[id]==r-l+1){
		for(auto t:vec[id]){
			hv[t]--;
			if(hv[t]==1) find(1,1,n,x[t],y[t]);
		}
	}
	else if(sum[id]==r-l){
		for(auto t:vec[id]){
			hv[t]-=sum[id];
			if(hv[t]==1) find(1,1,n,x[t],y[t]);
		}
	}
	if(l==r) return;
	int mid=(l+r)/2;
	if(p<=mid) del(id<<1,l,mid,p);
	else del(id<<1|1,mid+1,r,p);
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n+1;i++) f[i]=i,col[i]=-1;
	int opt,z;
	for(int j=1;j<=q;j++){
		opt=readint();
		if(opt==0){
			x[j]=readint(); y[j]=readint(); z=readint();
			if(z){
				hv[j]=y[j]-x[j]+1;
				add(1,1,n,x[j],y[j],j);
				if(hv[j]==1) find(1,1,n,x[j],y[j]);
			}
			else{
				for(int i=getf(x[j]);i<=y[j];i=getf(i+1)) del(1,1,n,i),col[i]=0,f[i]=i+1;
			}
		}
		else{
			int i=readint();
			if(col[i]==-1) printf("N/A\n");
			else if(col[i]==0) printf("NO\n");
			else printf("YES\n");
		}
	}
	return 0;
}