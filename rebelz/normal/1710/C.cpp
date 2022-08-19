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

const int cys=998244353;
int n;
int a[200005];
ll d[200005][8][8];
char s[200005];

ll mod(ll x){return x>=cys?x-cys:x;}
void add(ll &x,ll y){x=mod(x+y);}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	d[0][0][7]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<8;j++){
			for(int k=0;k<8;k++){
				if(!d[i][j][k]) continue;
				for(int n1=0;n1<=(k&1?a[i+1]:1);n1++){
					for(int n2=0;n2<=(k&2?a[i+1]:1);n2++){
						for(int n3=0;n3<=(k&4?a[i+1]:1);n3++){
							int j1=j,k1=0;
							k1^=(k&1)&(n1==a[i+1]);
							k1^=(k&2)&((n2==a[i+1])<<1);
							k1^=(k&4)&((n3==a[i+1])<<2);
							if(n1==n2&&n1==n3) add(d[i+1][j1][k1],d[i][j][k]);
							else if(n1!=n2&&n1!=n3) add(d[i+1][j1|2][k1],d[i][j][k]);
							else if(n2!=n1&&n2!=n3) add(d[i+1][j1|4][k1],d[i][j][k]);
							else add(d[i+1][j1|1][k1],d[i][j][k]);
						}
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<8;i++) add(ans,d[n][7][i]);
	printf("%lld\n",ans);
	return 0;
}