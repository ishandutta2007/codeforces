#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
 
#define X first
#define Y second
#define PB push_back
 
using namespace std;
 
typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
 
const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
 
inline int add(int A, int B) { if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }
 
int n, p[N], dpL[N], dpR[N], cnt = 0;
 
int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", p + i);
	}
	int naj = 0;
	for(int i = 0;i < n;i++){
		int dulj = 0;
		while(i + 1 < n && p[i + 1] > p[i])
			i++, dulj++;
		dpL[i] = dulj;
		if(dulj > naj)
			cnt = 0, naj = dulj;
		if(dulj == naj)
			cnt++;
	}
	for(int i = n - 1;i >= 0;i--){
		int dulj = 0;
		while(i > 0 && p[i - 1] > p[i])
			i--, dulj++;
		dpR[i] = dulj;
		if(dulj > naj)
			cnt = 0, naj = dulj;
		if(dulj == naj)
			cnt++;
	}
	if((naj & 1) || cnt > 2){
		printf("0\n");
		return 0;
	}
	int sol = 0;
	for(int i = 0;i < n;i++){
		if((dpL[i] || !i) && (dpR[i] || i == n - 1) && 0 && max(dpL[i], dpR[i]) == naj && cnt == 1)
			sol++;
		if(dpL[i] == naj && dpR[i] == naj && cnt == 2)
			sol++;
	}
	printf("%d\n", sol);
	return 0;
}