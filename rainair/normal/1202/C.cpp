#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;

char str[MAXN];
int a[MAXN],b[MAXN];
int sma[MAXN],smb[MAXN];

inline bool chk(int a[],int b[],int n){
	if(n == 0) return 0;
	int mx = 0,mn = 0;
	FOR(i,1,n) mx = std::max(mx,a[i]),mn = std::min(mn,a[i]);
	int p1 = n,p2 = 0;
	FOR(i,0,n){
		if(a[i] == mx){
			p1 = std::min(p1,i);
		}
		if(a[i] == mn){
			p2 = std::max(p2,i);
		}
	}
	if(p2 < p1-1) return 1;
	p1 = 0;p2 = n;
	FOR(i,0,n){
		if(a[i] == mx){
			p1 = std::max(p1,i);
		}
		if(a[i] == mn){
			p2 = std::min(p2,i);
		}
	}
	if(p1 < p2-1) return 1;
	return 0;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",str+1);
		int n = strlen(str+1),n1=0,n2=0;
		FOR(i,1,n){
			if(str[i] == 'W' || str[i] == 'S') a[++n1] = (str[i]=='W'?1:-1);
			if(str[i] == 'A' || str[i] == 'D') b[++n2] = (str[i]=='A'?1:-1);
		}
		FOR(i,1,n1) sma[i] = sma[i-1]+a[i];
		FOR(i,1,n2) smb[i] = smb[i-1]+b[i];
		int mxa=0,mna=0,mxb=0,mnb=0;
		FOR(i,1,n1) mxa = std::max(mxa,sma[i]),mna = std::min(mna,sma[i]);
		FOR(i,1,n2) mxb = std::max(mxb,smb[i]),mnb = std::min(mnb,smb[i]);
		LL ans = 1ll*(mxa-mna+1)*(mxb-mnb+1);
		if(chk(sma,a,n1)) ans = std::min(ans,1ll*(mxa-mna)*(mxb-mnb+1));
		if(chk(smb,b,n2)) ans = std::min(ans,1ll*(mxa-mna+1)*(mxb-mnb));
		printf("%lld\n",ans);
		FOR(i,0,n) sma[i] = smb[i] = a[i] = b[i] = 0;
	}
	return 0;
}