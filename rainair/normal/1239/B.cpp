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

const int MAXN = 3e5 + 5;
int n;
char str[MAXN],t[MAXN];
int sm[MAXN],id[MAXN];
int pre[MAXN],suf[MAXN];

int main(){
	scanf("%d",&n);
	scanf("%s",str+1);FOR(i,1,n) t[i] = str[i],id[i] = i;
	FOR(i,1,n) sm[i] = sm[i-1]+(str[i]=='('?1:-1);
	int mn = 1e9,ps = -1;
	FOR(i,1,n) if(sm[i] < mn) mn = sm[i],ps = i;
	if(sm[n] != 0){
		puts("0\n1 1");return 0;
	}
	int _ = 0;
	FOR(i,ps+1,n) str[++_] = t[i],id[_] = i;
	FOR(i,1,ps) str[++_] = t[i],id[_] = i;
	FOR(i,1,n) sm[i] = sm[i-1]+(str[i]=='('?1:-1);
	// printf("%s\n",str+1);
	/*
	'('')',>=2,2
	*/
	// FOR(i,1,n) DEBUG(sm[i]);
	//  2
	int mx = 0,mxl = 1,mxr = 1;
	int s = 0;
	for(int l = 1,r = 1;l <= n;l = r+1){
		r = l;
		while(r <= n && sm[r] >= 2) ++r;
		if(l == r) continue;
		int cnt = 0;FOR(i,l,r-1) cnt += (sm[i]==2);
		if(cnt > mx){
			mx = cnt;
			mxl = l;
			mxr = r;
		}
	}
	std::swap(str[mxl],str[mxr]);
	FOR(i,1,n) sm[i] = sm[i-1]+(str[i]=='('?1:-1);
	mx = 0;
	FOR(i,1,n) mx += (sm[i] == 0);
	std::swap(str[mxl],str[mxr]);
	FOR(i,1,n) sm[i] = sm[i-1]+(str[i]=='('?1:-1);
	for(int l = 1,r = 1;l <= n;l = r+1){
		r = l;
		while(r <= n && sm[r] >= 1) ++r;
		if(l == r) continue;
		int cnt = 0;FOR(i,l,r-1) cnt += (sm[i]==1);
		if(cnt > mx){
			mx = cnt;
			mxl = l;
			mxr = r;
		}
	}
	std::swap(str[mxl],str[mxr]);
	FOR(i,1,n) sm[i] = sm[i-1]+(str[i]=='('?1:-1);
	mn = 1e9;FOR(i,1,n) mn = std::min(mn,sm[i]);
	int ans = 0;FOR(i,1,n) ans += (sm[i]==mn);
	printf("%d\n%d %d\n",ans,id[mxl],id[mxr]);
	return 0;
}