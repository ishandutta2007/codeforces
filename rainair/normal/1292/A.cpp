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

const int MAXN = 3e5 + 5;
int cnt1,cnt2,cnt3;
bool mp[3][MAXN];
int b[2];

int main(){
	int n,q;scanf("%d%d",&n,&q);
	FOR(i,1,q){
		int x,y;scanf("%d%d",&x,&y);
		--x;
		if(mp[x][y]){
			if(mp[x^1][y]) cnt1--;
			if(y-1 >= 1) if(mp[x^1][y-1]) b[x]--;
			if(y+1 <= n) if(mp[x^1][y+1]) b[x^1]--;
			mp[x][y] = 0;
		}
		else{
			if(mp[x^1][y]) cnt1++;
			if(y-1 >= 1) if(mp[x^1][y-1]) b[x]++;
			if(y+1 <= n) if(mp[x^1][y+1]) b[x^1]++;
			mp[x][y] = 1;
		}
		if(!cnt1 && !b[0] && !b[1]) puts("Yes");
		else puts("No");
		// puts((!(cnt1+cnt2+cnt3)) ? "Yes" : "No");
	}
	return 0;
}