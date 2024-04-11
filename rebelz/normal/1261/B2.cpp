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

struct node{
	int k,p,id;
	bool operator<(const node c)const{return k<c.k;}
}b[200005];

int n,m,q;
int a[200005],p[200005],ans[200005],val[600000];
vector<int> v[200005];

void change(int id,int l,int r,int x){
	val[id]++;
	if(l==r) return;
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x);
	else change(id<<1|1,mid+1,r,x);
}

int query(int id,int l,int r,int x){
	if(l==r) return l;
	int mid=(l+r)/2;
	if(x<=val[id<<1]) return query(id<<1,l,mid,x);
	else return query(id<<1|1,mid+1,r,x-val[id<<1]);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) p[i]=a[i]=readint();
	sort(p+1,p+n+1); m=unique(p+1,p+n+1)-p-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+m+1,a[i])-p;
	for(int i=1;i<=n;i++) v[a[i]].push_back(i);
	q=readint();
	for(int i=1;i<=q;i++) b[i].k=readint(),b[i].p=readint(),b[i].id=i;
	sort(b+1,b+q+1);
	int now=1,cnt=0;
	for(int i=m;i>=1;i--){
		for(auto x:v[i]){
			cnt++;
			change(1,1,n,x);
			while(b[now].k==cnt) ans[b[now].id]=query(1,1,n,b[now].p),now++;
		}
	}
	for(int i=1;i<=q;i++) printf("%d\n",p[a[ans[i]]]);
	printf("\n");
	return 0;
}