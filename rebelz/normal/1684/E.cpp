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

int n,k;
int a[100005];
ll sum1[300005],sum2[300005];
bool vis[100005];
map<int,int> bk;

void build(int id,int l,int r){
	sum1[id]=sum2[id]=0;
	if(l==r) return;
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void change(int id,int l,int r,int x,int c){
	sum1[id]+=c,sum2[id]+=c*x;
	if(l==r) return;
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x,c);
	else change(id<<1|1,mid+1,r,x,c);
}

int query(int id,int l,int r,int x){
	if(sum2[id]<=x) return sum1[id];
	if(l==r) return x/l;
	int mid=(l+r)/2;
	if(sum2[id<<1]<=x) return sum1[id<<1]+query(id<<1|1,mid+1,r,x-sum2[id<<1]);
	else return query(id<<1,l,mid,x);
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		bk.clear();
		for(int i=1;i<=n;i++) bk[a[i]]++;
		for(int i=0;i<=n;i++) vis[i]=0;
		build(1,1,n);
		for(auto r:bk){
			change(1,1,n,r.se,1);
			if(r.fi<=n) vis[r.fi]=1;
		}
		int ans=bk.size(),num=0;
		for(int i=0;i<n;i++){
			if(vis[i]) change(1,1,n,bk[i],-1);
			else num++;
			if(num>k) break;
			chkmin(ans,(int)bk.size()+num-query(1,1,n,num)-(i+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}