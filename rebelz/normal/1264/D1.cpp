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

const int cys=998244353;
int n;
ll d1[2005][2005],d2[2005][2005];
char s[2005];

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	d2[n+1][0]=1;
	for(int i=n;i>=1;i--){
		if(s[i]=='?'){
			for(int j=0;j<=n-i+1;j++) d2[i][j]=mod((j>0?d2[i+1][j-1]:0)+d2[i+1][j]);
		}
		else if(s[i]==')'){
			for(int j=1;j<=n-i+1;j++) d2[i][j]=d2[i+1][j-1];
		}
		else if(s[i]=='('){
			for(int j=0;j<=n-i+1;j++) d2[i][j]=d2[i+1][j];
		}
	}
	for(int i=1;i<=n;i++) for(int j=n-i+1;j>=0;j--) d2[i][j]=mod(d2[i][j]+d2[i][j+1]);
	ll ans=0;
	d1[0][0]=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='?'){
			for(int j=0;j<=i;j++) d1[i][j]=mod((j>0?d1[i-1][j-1]:0)+d1[i-1][j]);
			for(int j=1;j<=i;j++) ans=(ans+d1[i-1][j-1]*d2[i+1][j])%cys;
		}
		else if(s[i]=='('){
			for(int j=1;j<=i;j++) d1[i][j]=d1[i-1][j-1];
			for(int j=1;j<=i;j++) ans=(ans+d1[i-1][j-1]*d2[i+1][j])%cys;
		}
		else if(s[i]==')'){
			for(int j=0;j<=i;j++) d1[i][j]=d1[i-1][j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}