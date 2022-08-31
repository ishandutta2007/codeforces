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

int n,m,cnt;
ll a1[200005],b1[200005],s1[200005],p[200005],pre[200005],suf[200005];
pll op[200005];
char res[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		int x,y;
		cnt=0;
		for(int i=1;i<=n;i++){
			x=readint(); y=readint();
			op[i]=mp(x,y);
			p[++cnt]=x;
		}
		for(int i=1;i<=n;i++) res[i]='0';
		res[n+1]=0;
		sort(p+1,p+cnt+1);
		cnt=unique(p+1,p+cnt+1)-p-1;
		for(int i=1;i<=cnt;i++) a1[i]=b1[i]=s1[i]=0;
		for(int i=1;i<=n;i++){
			int pl=lower_bound(p+1,p+cnt+1,op[i].fi)-p;
			int p1=lower_bound(p+1,p+cnt+1,op[i].fi-op[i].se+1)-p;
			int p2=upper_bound(p+1,p+cnt+1,op[i].fi+op[i].se-1)-p-1;
			a1[p1]++,a1[pl]--;
			s1[p1]+=op[i].se-p[pl],s1[pl]-=op[i].se-p[pl];
			b1[pl]++,b1[p2+1]--;
			s1[pl]+=op[i].se+p[pl],s1[p2+1]-=op[i].se+p[pl];
		}
		for(int i=1;i<=cnt;i++) a1[i]+=a1[i-1],b1[i]+=b1[i-1],s1[i]+=s1[i-1];
		for(int i=1;i<=cnt;i++) s1[i]+=a1[i]*p[i]-b1[i]*p[i];
		int lf=0,rg=0;
		for(int i=1;i<=cnt;i++){
			if(s1[i]>m){
				if(!lf) lf=i;
				rg=i;
				pre[i]=s1[i]-m-p[i];
				suf[i]=s1[i]-m+p[i];
			}
			else pre[i]=suf[i]=-(1ll<<60);
		}
		pre[0]=suf[cnt+1]=-(1ll<<60);
		for(int i=1;i<=cnt;i++) chkmax(pre[i],pre[i-1]);
		for(int i=cnt;i>=1;i--) chkmax(suf[i],suf[i+1]);
		if(!lf){
			for(int i=1;i<=n;i++) putchar('1');
			putchar('\n');
			continue;
		}
		for(int i=1;i<=n;i++){
			if(op[i].fi-op[i].se+1>p[lf]) continue;
			if(op[i].fi+op[i].se-1<p[rg]) continue;
			int pl=lower_bound(p+1,p+cnt+1,op[i].fi)-p;
			if(pre[pl]+p[pl]-op[i].se>0) continue;
			if(suf[pl]-p[pl]-op[i].se>0) continue;
			res[i]='1';
		}
		puts(res+1);
	}
	return 0;
}