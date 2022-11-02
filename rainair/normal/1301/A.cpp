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

const int MAXN = 1e5 + 5;
char A[MAXN],B[MAXN],C[MAXN];
int n;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s%s%s",A+1,B+1,C+1);
		int n = strlen(A+1);bool flag=  true;
		FOR(i,1,n){
			if(A[i] == C[i] || B[i] == C[i]) continue;
			puts("NO");flag = false;break;
		}
		if(!flag) continue;
		puts("YES");
	}
	return 0;
}