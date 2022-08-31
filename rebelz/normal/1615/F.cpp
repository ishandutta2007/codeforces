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

const int cys=1000000007;
int n;
char s[2][2005];
pll d[4005],f[4005];

ll mod(ll x){return x>=cys?x-cys:x;}
void add(ll &x,ll y){x=mod(x+y);}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s%s",s[0]+1,s[1]+1);
		for(int i=0;i<=n+n;i++) d[i].fi=d[i].se=f[i].fi=f[i].se=0;
		d[n]=mp(1,0);
		for(int i=0;i<n;i++){
			int c0=(s[0][i+1]!='1')&(s[1][i+1]!='0');
			int c2=(s[0][i+1]!='0')&(s[1][i+1]!='1');
			int c1=(s[0][i+1]=='?'?2:1)*(s[1][i+1]=='?'?2:1)-c0-c2;
			if(i&1) swap(c0,c2);
			for(int j=-i;j<=i;j++){
//				cout<<"test "<<i<<' '<<j<<' '<<d[j+n].fi<<' '<<d[j+n].se<<endl;
				add(f[j+n].fi,d[j+n].fi*c1%cys);
				add(f[j+n].se,d[j+n].se*c1%cys);
				add(f[j+n+1].fi,d[j+n].fi*c2%cys);
				add(f[j+n+1].se,(d[j+n].se*c2+(j>=0?-(i+1):i+1)*d[j+n].fi)%cys*c2%cys);
				add(f[j+n-1].fi,d[j+n].fi*c0%cys);
				add(f[j+n-1].se,(d[j+n].se*c0+(j>0?i+1:-(i+1))*d[j+n].fi)%cys*c0%cys);
			}
			for(int j=-(i+1);j<=i+1;j++) d[j+n]=f[j+n],f[j+n]=mp(0,0);
		}
		printf("%lld\n",d[n].se);
	}
	return 0;
}