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

const int MAXN = 5000+5;

int n;
int s[MAXN],t[MAXN];
char str[MAXN];

inline void f(char s[],int ans[]){
	for(int i = 1;i <= n;i += 2) ans[(i+1)>>1] = (s[i]-'0')*2+(s[i+1]-'0');
}

int cnt[4];

inline void gao(int s[],int t){
	std::reverse(s+1,s+t+1);
	FOR(i,1,t) if(s[i] >= 1 && s[i] <= 2) s[i] = 3-s[i];
}

inline void Solve(){
	scanf("%s",str+1);n = strlen(str+1);
	f(str,s);scanf("%s",str+1);f(str,t);n >>= 1;CLR(cnt,0);
	FOR(i,1,n) cnt[s[i]]++,cnt[t[i]]--;
	// FOR(i,1,n) printf("%d ",s[i]);puts("");
	// FOR(i,1,n) printf("%d ",t[i]);puts("");
	if(cnt[0] || cnt[3] || (cnt[1]+cnt[2])){
		puts("-1");return;
	}
	bool flag = cnt[1]==0;int ext = 0;
	FOR(i,1,n){
		if(flag) break;
		cnt[s[i]]--;cnt[3-s[i]]++;
		if(!cnt[1]){
			ext = i;
			gao(s,i);
			flag = 1;
		}
	}
	if(!flag) FOR(i,1,n) cnt[s[i]]++,cnt[3-s[i]]--;
	FOR(i,1,n){
		if(flag) break;
		cnt[t[i]]++;cnt[3-t[i]]--;
		if(!cnt[1]){
			ext = -i;
			gao(t,i);
			flag = 1;
		}
	}
	std::vector<int> ans;
	if(ext > 0) ans.pb(ext);
	FOR(i,1,n-1){
		int pos = -1;
		FOR(j,i,n){
			if(s[j] == t[i]){
				pos = j;break;
			}
			// if(t[i] >= 1 && t[i] <= 2){
				// if(s[j]+t[i] == 3){
					// pos = j;break;
				// }
			// }
			// else{
				// if(s[j] == t[i]){
					// pos = j;break;
				// }
			// }
		}
		// if(i == 2) DEBUG(pos);
		if(pos > 1) ans.pb(pos-1),gao(s,pos-1);
		ans.pb(pos);gao(s,pos);
		// if(i == 2){
			// FOR(i,1,n) DEBUG(s[i]);
		// }
	}
	// flag = 1;
	// FOR(i,1,n) flag &= s[i]==t[i];
	if(n > 1) ans.pb(n-1),gao(s,n-1);
	// FOR(i,1,n) assert(s[i]==t[i]);
	if(ext < 0) ans.pb(-ext);
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d ",2*x);
	puts("");
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}