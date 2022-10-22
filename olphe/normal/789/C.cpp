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

long long int N;
long long int num[100001];
long long int o_sum[100001];
long long int e_sum[100001];
long long int o_min[100001];
long long int e_min[100001];
long long int ans;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	for (int i = 1; i < N; i++) {
		if (i % 2) {
			o_sum[i] = o_sum[i-1] + abs(num[i] - num[i + 1]);
			o_min[i] = o_min[i - 1];
		}
		else{
			o_sum[i] = o_sum[i-1] - abs(num[i] - num[i + 1]); 
			o_min[i] = min(o_min[i - 1], o_sum[i]);
		}
	}
	for (int i = 1; i < N; i++) {
		//cout << o_sum[i] << " " << o_min[i]<<endl;
		ans = max(ans, o_sum[i] - o_min[i]);
	}
	for (int i = 2; i < N; i++) {
		if (i % 2) {
			e_sum[i] = e_sum[i-1] - abs(num[i] - num[i + 1]);
			e_min[i] = min(e_min[i - 1], e_sum[i]);
		}
		else {
			e_sum[i] = e_sum[i-1] + abs(num[i] - num[i + 1]);
			e_min[i] = e_min[i - 1];
		}
		
	}
	for (int i = 2; i < N; i++) {
		//cout << e_sum[i] << " " << e_min[i]<<endl;
		ans = max(ans, e_sum[i] - e_min[i]);
	}
	cout << ans << endl;
	return 0;
}