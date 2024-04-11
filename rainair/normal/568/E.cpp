#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

inline char nc(){
    #define SIZE 1000000+3
    static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
    if(p1 == p2){
        p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
}
 
inline void read(int &x){
    x = 0;int flag = 0;char ch = nc();
    while(!isdigit(ch)){
        if(ch == '-') flag = 1;
        ch = nc();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^'0');
        ch = nc();
    }
    if(flag) x = -x;
}

const int MAXN = 2e5 + 5;
int a[MAXN],b[MAXN],n,m;
int G[MAXN],tp;
std::vector<int> ans[MAXN],whi;
bool used[MAXN];
std::multiset<int> S;

inline bool cmp(int x,int y){
	return a[x] > a[y];
}

int main(){
	read(n);
	FOR(i,1,n) read(a[i]);
	FOR(i,1,n) if(a[i] == -1) whi.pb(i);
	read(m);
	FOR(i,1,m) read(b[i]),S.insert(b[i]);
	std::sort(b+1,b+m+1);
	b[m+1] = 1e9+7;
	FOR(i,1,n+233) G[i] = 1e9+7;
	int head = 1;
	if(a[1] == -1){
		G[tp = 1] = b[1];ans[tp].pb(1);
		a[1] = b[1];S.erase(S.find(a[1]));++head;
	}
	else G[tp = 1] = a[1],ans[tp].pb(1);
	FOR(i,2,n){
		if(a[i] != -1){
			if(G[tp] < a[i]) G[++tp] = a[i],ans[tp].pb(i);
			else{
				int p = std::lower_bound(G+1,G+tp+1,a[i])-G;
				G[p] = a[i];ans[p].pb(i);
			}
		}
		else{
			// ROF(i,tp,0){
				// if(G[i] == 1e9+7) break;
				// int t = std::upper_bound(b+1,b+m+2,G[i])-b;
				// DEBUG(b[t]);DEBUG(G[i]);
				// if(t <= m) G[i+1] = std::min(G[i+1],b[t]);
			// }
			int now = tp;
			ROF(i,m,1){
				while(G[now]>=b[i]) now--;
				G[now+1] = b[i];
			}
			while(G[tp+1] != 1e9+7) tp++;
		}
	}
	// FOR(i,1,n) printf("%d ",G[i]);puts("");
	// if(n == 100000 && a[1] == 80061) printf("%d\n",tp);
	int lst=1e9+7;
	int now = (int)whi.size()-1;
	// FOR(i,1,tp){
		// for(auto x:ans[i]) DEBUG(x);
		// puts("");
	// }
	// DEBUG(1);
	int tot = m;
	FOR(i,1,tp) std::sort(all(ans[i]),cmp);
	ROF(i,tp,1){
		bool flag = false;
		FOR(j,0,(int)ans[i].size()-1){
			if(lst > ans[i][j] && (lst==1e9+7||a[ans[i][j]]<a[lst])){
				lst = ans[i][j];
				flag = true;break;
			}
		}
		if(flag) continue;
		while(whi[now] >= lst) now--;
		if(lst == 1e9+7){
			lst = whi[now];
			auto x = S.end();--x;
			a[lst] = *x;
			S.erase(x);
			continue;
		}
		// DEBUG(a[lst]);DEBUG(lst);
		// int t = std::lower_bound(b+head,b+m+1,a[lst])-b;
		while(b[tot] >= a[lst]) tot--;//May TLE
		int t = b[tot];
		S.erase(S.find(t));
		lst = whi[now];
		a[lst] = t;
		now--;
	}
	FOR(i,1,n){
		if(a[i] == -1){
			a[i] = *S.begin();S.erase(S.begin());
		}
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}