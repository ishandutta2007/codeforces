#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

int N,M,K;
int a,b;
bool flag[2000000];
int ans;


int main(){
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		flag[a] = true;
	}
	ans = 1;
	if (flag[1]) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &a, &b);
		if (ans == a)ans = b;
		else if (ans == b)ans = a;
		if (flag[ans]) {
			cout << ans << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}