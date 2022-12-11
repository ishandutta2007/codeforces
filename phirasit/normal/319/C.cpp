#include <stdio.h>
#include <vector>

#define N 100010

using namespace std;

vector<int> curve;

long long dp[N];
long long A[N], B[N];
int n;

long long H(int idx, long long x) {
	return dp[idx] + x * B[idx];
}
double find_x(int i, int j) {
	double dDP = dp[i] - dp[j], dB = B[j] - B[i];
	return dDP / dB;
}
// add y = m * x + c
void add(int idx) {
	int sz = curve.size();
	while(sz >= 2 && find_x(idx, curve[sz-2]) >= find_x(idx, curve[sz-1])) {
		curve.pop_back();
		sz = curve.size();
	}
	curve.push_back(idx);
}
int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		scanf("%I64d", &A[i]);
	}
	for(int i = 1;i <= n;i++) {
		scanf("%I64d", &B[i]);
	}
	for(int i = 1;i <= n;i++) {
		if(i == 1) {
			dp[i] = 0;
		}else {
			int a = 0, b = curve.size() - 1;
			while(a < b) {
				int mid = (a + b) / 2;
				int idx1 = curve[mid], idx2 = curve[mid+1];
				if(H(idx1, A[i]) < H(idx2, A[i])) {
					b = mid;
				}else {
					a = mid + 1;
				}
			}
			dp[i] = H(curve[a], A[i]);
		}
		add(i);
	}
	printf("%I64d\n", dp[n]);
	return 0;
}