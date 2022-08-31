//      hello world


//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>

#define oo 			0xBADC0DE
#define s(n)			scanf("%d",&n)
#define sl(n) 			scanf("%lld",&n)
#define sf(n) 			scanf("%lf",&n)
#define fill(a,v) 		memset(a, v, sizeof a)
#define ull 			unsigned long long
#define ll 				long long
#define bitcount 		__builtin_popcount
#define all(x) 			x.begin(), x.end()
#define pb( z ) 		push_back( z )
#define gcd				__gcd

#define FOR(i,n) for (int i=0; i < (n); i++)

using namespace std;
int a[1000007];
int parent[1000007];
int n;
int getId(int x) {
	int y = lower_bound(a, a+n, x) - a;
	if (a[y] == x) return y;
	return -1;
}
int find(int x) {
	if (x==parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	if (x==-1 || y==-1) return;
	x = find(x); y=find(y);
	parent[x] = y;
}

int main() {
	
	s(n);
	for (int i=0; i < n; i++) s(a[i]);
	sort(a, a+n);
	n = unique(a, a+n) - a;
	for (int i=0; i < n; i++) parent[i] = i;
	
	int limit = (int)1e7 + 1;
	for (int N=1; ; N++) {
		int N2 = N*N;
		if (N2 > limit) break;
		for (int M=N+1; ; M++) {
			int M2 = M*M;
			int A = M2 - N2;
			int B = 2*M*N;
			int C = M2 + N2;
			int cnt = (A > limit) + (B > limit) + (C > limit);
			if (cnt > 1) break;
			if (gcd(A,B) == 1 && gcd(B,C) == 1 && gcd(C,A) == 1) {
				int ai = getId(A);
				int bi = getId(B);
				int ci = getId(C);
				merge(ai,bi);
				merge(bi,ci);
				merge(ci,ai);
			}
		}
	}
	int sol = 0;
	for (int i=0; i < n; i++)
	if (find(i) == i) sol++;
	printf("%d\n", sol);
	
	return 0;
}