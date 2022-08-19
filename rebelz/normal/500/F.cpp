#include<bits/stdc++.h>

#define y1 dmytxdy
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

const int N=20000,M=4000;
int n,p,q,top;
int now[4005],ans[20005],tmp[20][4005];
vector<pii> vec[70000],qry[20005];

void change(int id,int l,int r,int ql,int qr,pii c){
	assert(l<=ql&&qr<=r);
	if(l==ql&&r==qr) return (void)(vec[id].pb(c));
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
}

void solve(int id,int l,int r){
	for(auto r:vec[id]){
		for(int i=M-r.fi;i>=0;i--) chkmax(now[i+r.fi],now[i]+r.se);
	}
	if(l==r){
		for(auto r:qry[l]) ans[r.se]=now[r.fi];
		return;
	}
	top++;
	memcpy(tmp[top],now,sizeof(now));
	int mid=(l+r)/2;
	solve(id<<1,l,mid);
	memcpy(now,tmp[top],sizeof(now));
	solve(id<<1|1,mid+1,r);
	top--;
}

int main(){
	n=readint(); p=readint();
	int x,y,z;
	for(int i=1;i<=n;i++){
		x=readint(); y=readint(); z=readint();
		change(1,1,N,z,min(N,z+p-1),mp(x,y));
	}
	q=readint();
	for(int i=1;i<=q;i++){
		x=readint(); y=readint();
		qry[x].pb(mp(y,i));
	}
	solve(1,1,N);
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}