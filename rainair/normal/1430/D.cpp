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
char str[MAXN];int n;
int f[MAXN],cnt[MAXN];
P a[MAXN];
int len[MAXN];
bool del[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",str+1);
		std::set<std::pair<int,int> > S;
		int tot = 0;
		for(int l = 1,r = 1;l <= n;l = r+1){
			while(r <= n && str[r+1] == str[l]) ++r;
			a[++tot] = MP(l,r);len[tot] = r-l+1;
			if(r-l) S.insert(MP(l,tot));
		}
		int ans = 0;
		FOR(i,1,tot){
			ans++;
			if(S.empty()){
				++i;continue;
			}
			int p = S.begin()->se;
			len[p]--;
			if(len[p] == 1) S.erase(S.begin());
			if(S.count(MP(a[i].fi,i))) S.erase(MP(a[i].fi,i));
		}
		printf("%d\n",ans);
	}
	return 0;
}