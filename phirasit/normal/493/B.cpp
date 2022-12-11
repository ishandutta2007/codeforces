#include <stdio.h>
#include <vector>

using namespace std;

vector<long long> seq_a, seq_b;
int n;

long long sum_a, sum_b;

int main() {
	scanf("%d", &n);
	sum_a = sum_b = 0;
	long long ls;
	for(int i = 0;i < n;i++) {
		long long val;
		scanf("%I64d", &val);
		if(val > 0) {
			sum_a += val;
			seq_a.push_back(val);
		}else {
			sum_b -= val;
			seq_b.push_back(-val);
		}
		ls = val;
	}
	if(sum_a != sum_b) {
		printf("%s\n", sum_a > sum_b ? "first" : "second");
	}else {
		for(int i = 0;i < seq_a.size() && i < seq_b.size();i++) {
			if(seq_a[i] != seq_b[i]) {
				printf("%s\n", seq_a[i] > seq_b[i] ? "first" : "second");
				return 0;
			}
		}
		if(seq_a.size() != seq_b.size()) {
			printf("%s\n", seq_a.size() > seq_b.size() ? "first" : "second");
		}else {
			printf("%s\n", ls > 0 ? "first" : "second");
		}
	}
	return 0;
}