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
char str[233333];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",str+1);
		int n = strlen(str+1);
		int l=n+233,r=0;
		FOR(i,1,n){
			if(str[i] == '1') l = std::min(l,i),r = std::max(r,i);
		}
		int ans = 0;
		FOR(i,l,r) ans += (str[i]=='0');
		printf("%d\n",ans);
	}
	return 0;
}