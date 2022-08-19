#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,k,now,L=1,R=0;
ll a[100005],cnt[100005],d[25][100005];

void add(int x){now+=cnt[a[x]],cnt[a[x]]++;}
void del(int x){cnt[a[x]]--,now-=cnt[a[x]];}

void solve(int t,int l,int r,int ql,int qr){
	if(l>r) return;
	int mid=(l+r)/2,nr=mid,nl=min(mid,qr)+1;
	while(R<nr) add(++R);
	while(L>nl) add(--L);
	while(L<nl) del(L++);
	while(R>nr) del(R--);
	nl--;
	ll nowa=now+d[t-1][nl],opt=nl;
	for(int i=nl-1;i>=ql;i--){
		add(--L);
		if(chkmin(nowa,d[t-1][i]+now)) opt=i;
	}
	d[t][mid]=nowa;
	solve(t,l,mid-1,ql,opt),solve(t,mid+1,r,opt,qr);
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	memset(d,0x3f,sizeof(d));
	d[0][0]=0;
	for(int i=1;i<=k;i++) solve(i,0,n,0,n);
	printf("%lld\n",d[k][n]);
	return 0;
}