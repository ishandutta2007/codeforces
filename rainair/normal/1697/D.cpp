#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define pf emplace_front
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000 + 5;
int n;
int a[MAXN];char tmp[4];

char s[MAXN];

inline int query1(int p){
#ifdef RainAir
	return s[p]-'a';
#endif
	printf("? 1 %d\n",p);std::fflush(stdout);
	scanf("%s",tmp);return tmp[0]-'a';
}

int t[26];

inline int query2(int l,int r){
#ifdef RainAir
	CLR(t,0);
	FOR(i,l,r) ++t[s[i]-'a'];
	int ans = 0;
	FOR(i,0,25) if(t[i]) ++ans;
	return ans;
#endif
	printf("? 2 %d %d\n",l,r);std::fflush(stdout);
	int x;scanf("%d",&x);return x;
}

std::vector<P<int,int> > S;

int main(){
	scanf("%d",&n);
#ifdef RainAir
	scanf("%s",s+1);
#endif
	a[1] = query1(1);S.pb(1,a[1]);
	FOR(i,2,n){
		int l = 0,r = SZ(S)-1,ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(query2(S[mid].fi,i) != 1+SZ(S)-mid) ans = mid,l = mid+1;
			else r = mid-1;
		}
		if(ans == -1){
			a[i] = query1(i);
		}
		else{
			a[i] = S[ans].se;
			S.erase(S.begin()+ans);
		}
		S.pb(i,a[i]);
	}
	printf("! ");
	FOR(i,1,n) putchar('a'+a[i]);
	puts("");std::fflush(stdout);
	return 0;
}