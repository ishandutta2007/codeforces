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
char str[MAXN];
int n,q;
int sm[26][MAXN];
int pre[MAXN],suf[MAXN];

int main(){
	scanf("%s",str+1);
	scanf("%d",&q);n = strlen(str+1);
	FOR(i,1,n){
		FOR(j,0,25){
			sm[j][i] = sm[j][i-1]+((str[i]-'a')==j);
		}
	}
	FOR(i,2,n){
		if(str[i] != str[i-1]) pre[i] = i-1;
		else pre[i] = pre[i-1];
	}
	suf[n] = n+1;
	ROF(i,n-1,1){
		if(str[i] != str[i+1]) suf[i] = i+1;
		else suf[i] = suf[i+1];
	}
	// DEBUG(q);
	FOR(i,1,q){
		int l,r;scanf("%d%d",&l,&r);
		if(l == r || str[l] != str[r]){
			puts("Yes");
			continue;
		}
		int cnt = 0;
		FOR(j,0,25) if(sm[j][r]-sm[j][l-1] != 0) cnt++;
		puts(cnt>=3?"Yes":"No");
	}
	return 0;
}