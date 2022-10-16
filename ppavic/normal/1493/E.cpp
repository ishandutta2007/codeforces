#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef pair < ll, ll > pll;

const int N = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int OFF = (1 << 18);

char A[N], B[N];
int n;

int main(){
	scanf("%d %s %s", &n, A, B);
	if(A[0] != B[0]){
		for(int i = 0;i < n;i++)
			printf("1");
		printf("\n");
		return 0;
	}
	int st = 0;
	while(st < n && A[st] == B[st])
		st++;
	if(st == n){
		for(int i = 0;i < n;i++)
			printf("%c", A[i]);
		printf("\n");
		return 0;
	}
	bool Ad = 1, Bg = 1;
	for(int j = st + 1;j < n;j++){
		if(A[j] != '1') Ad = 0;
		if(B[j] != '0') Bg = 0;
	}
	for(int j = 0;j + 1 < n;j++){
		printf("%c", B[j]);
	}
	if(B[n - 1] == '1' || !Ad || !Bg)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}