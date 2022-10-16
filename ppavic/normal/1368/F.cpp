#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << 18);

int n, A[N], cnt;

int prebroji(){
	int ret = 0;
	for(int i = 0;i < n;i++)
		ret += A[i];
	return ret;
}

void odgovor(int p){
	int k; scanf("%d", &k); k--;
	for(int i = 0;i < p;i++)
		A[(k + i) % n] = 0;	
	/**
	int k = 0, sol = 0;
	for(int i = 0;i < n;i++){
		int cur = 0;
		for(int j = 0;j < p;j++)
			cur += A[(i + j) % n];
		if(cur > sol)
			k = i, sol = cur;
	}
	for(int i = 0;i < p;i++)
		A[(k + i) % n] = 0;	
	**/
}

void postavi(int p){
	vector < int > pitaj;
	for(int j = 0;j < p;j++){
		for(int i = j;i + 1 < n;i += p){
			if(A[i]) continue;
			pitaj.PB(i);
		}
	}
	printf("%d ", p);
	for(int i = 0;i < p;i++) {
		printf("%d ", pitaj[i] + 1);
		A[pitaj[i]] = 1;
	}
	printf("\n");
	fflush(stdout);
}



int main(){
	scanf("%d", &n);
	if(n == 1){
		printf("0\n");
		return 0;
	}
	int naj = 1, dos = 0;
	for(int i = 1;i <= n;i++){
		if(n - ((n + i - 1) / i) - i + 1 > dos){
			dos = n - ((n + i - 1) / i) - i + 1;
			naj = i;
		}
	}
	for(;prebroji() < dos;){
		postavi(naj);
		odgovor(naj);
	}
	printf("0\n");
	fflush(stdout);
	return 0;
}