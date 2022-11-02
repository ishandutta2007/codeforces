#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<LL,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5+5;
P st[MAXN];
#define int LL
int a[MAXN],n;
int tp;
LL t[MAXN];
int A[MAXN];
int M;
LL sm[MAXN],csm[MAXN],cnt[MAXN];
inline LL f(LL n,LL a,LL b,LL c){
	if(n < 0) return 0;
	if(a < 0) return f(n,-a,b+n*a,c);
	if(b < 0){
		if(!a) return 0;
		LL d = std::ceil((long double)(-b)/a);
		return f(n-d,a,b+a*d,c);
	}
	if(!a) return (b/c)*(n+1);
	if(a >= c || b >= c) return f(n,a%c,b%c,c)+(a/c)*n*(n+1)/2+(b/c)*(n+1);
	LL M = (a*n+b)/c;
	return n*M-f(M-1,c,c-b-1,a);
}

inline LL calc(int l,int r,LL k){
	if(sm[r]-sm[l-1] <= k) return cnt[l]*cnt[r];
	LL s = sm[r-1]-sm[l];
	LL A = ::A[l],B = ::A[r],CA = cnt[l],CB = cnt[r];
	LL gx = f(CA,-A,k-s,B)-std::max(0ll,(k-s)/B);
	gx -= f(CA,-A,k-B*CB-s,B)-std::max(0ll,(k-B*CB-s)/B);
	return gx;
}

inline bool chk(LL k){// <=k <=k <=k >= >k
	//  <= k 
	LL res = 0;
	FOR(i,1,M){
		LL l = std::min(k/A[i],cnt[i]);// 
		res += cnt[i]*l - l*(l-1)/2;
		sm[i] = sm[i-1]+A[i]*cnt[i];
		csm[i] = csm[i-1]+cnt[i];
	}
	int r = 1;
	FOR(l,1,M){// <=k
		if(A[l] > k) break;
		r = std::max(r,l+1);
		while(r <= M && sm[r]-sm[l-1] <= k) ++r;
		res += (csm[r-1]-csm[l])*cnt[l];
		while(r <= M && sm[r]-sm[l] <= k) res += calc(l,r,k),++r;
		res += calc(l,r,k);
	}
	LL m = n*(n+1)/2;
	return res >= m*(m+1)/2 - res;
}

signed main(){
	scanf("%lld",&n);
	FOR(i,1,n) scanf("%lld",a+i);
	FOR(i,1,n){
		int p = 0;
		st[++tp] = MP(a[i],i);
		FOR(j,1,tp){
			st[j].fi = std::__gcd(st[j].fi,a[i]);
			if(st[j].fi == st[p].fi) continue;
			st[++p] = st[j];
		}
		tp = p;
		FOR(j,1,tp-1) t[st[j].fi] += st[j+1].se-st[j].se;
		t[st[tp].fi] += i-st[tp].se+1;
	}
	FOR(i,1,MAXN-1) if(t[i]) A[++M] = i,cnt[M] = t[i];
	LL l = 1,r = 1e15,ans = -1;
	while(l <= r){
		LL mid = (l + r) >> 1;
		if(chk(mid)) ans = mid,r = mid-1;
		else l = mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}