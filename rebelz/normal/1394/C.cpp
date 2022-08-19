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

int n,m;
ll cnt[2],a[300005],b[300005],ta[300005],tb[300005];
char s[500005];

bool check(ll x,ll y,ll x1,ll x2,ll y1,ll y2,ll l1,ll r1){
	return x>=x1&&x<=x2&&y>=y1&&y<=y2&&y-x>=l1&&y-x<=r1;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		m=strlen(s+1);
		cnt[0]=cnt[1]=0;
		for(int i=1;i<=m;i++) cnt[s[i]=='B']++;
		a[i]=cnt[0],b[i]=cnt[1];
	}
	ll l=0,r=1e9,ret,optx,opty;
	while(l<=r){
		ll mid=(l+r)/2,x1=0,y1=0,x2=1e9,y2=1e9,l1=-1e9,r1=1e9;
		for(int i=1;i<=n;i++){
			chkmax(x1,a[i]-mid);
			chkmin(x2,a[i]+mid);
			chkmax(y1,b[i]-mid);
			chkmin(y2,b[i]+mid);
		}
		for(int i=1;i<=n;i++){
			chkmax(l1,b[i]-a[i]-mid);
			chkmin(r1,b[i]-a[i]+mid);
		}
		bool fl=0;
		if(x1<=x2&&y1<=y2&&l1<=y2-x1&&r1>=y1-x2&&l1<=r1){
			fl=1;
			if(check(x2,y1,x1,x2,y1,y2,l1,r1)) optx=x2,opty=y1;
			else if(check(y1-l1,y1,x1,x2,y1,y2,l1,r1)) optx=y1-l1,opty=y1;
			else if(check(x1,x1+l1,x1,x2,y1,y2,l1,r1)) optx=x1,opty=x1+l1;
			else assert(0);
		}
		if(fl) ret=mid,r=mid-1;
		else l=mid+1;
	}
	if(optx==0&&opty==0) optx++,opty++;
	printf("%lld\n",ret);
	for(int i=1;i<=opty;i++) printf("B");
	for(int i=1;i<=optx;i++) printf("N");
	printf("\n");
	return 0;
}