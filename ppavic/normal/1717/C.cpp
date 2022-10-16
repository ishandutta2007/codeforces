#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

#define PB push_back
#define X first
#define Y second

using namespace std;

typedef long long ll;

const int N = 2e5 + 500;

int n, A[N], B[N];

int main(){
	int T; scanf("%d", &T);
	for(;T--;){
		scanf("%d", &n);
		for(int i = 0;i < n;i++) scanf("%d", A + i);
		for(int i = 0;i < n;i++) scanf("%d", B + i);
		bool mogu = 1;
		for(int i = 0;i < n;i++) mogu &= A[i] <= B[i];
		for(int i = 0;i < n;i++) mogu &= (A[i] == B[i] || B[i] <= B[(i + 1) % n] + 1);
		printf(mogu ? "YES\n" : "NO\n");
	}
	return 0;
}