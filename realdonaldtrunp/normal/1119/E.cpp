#include"bits/stdc++.h"
#include "chrono"
using namespace std;
typedef long long ll;

#define MAX 300002

int n;

vector<long long int> v;

long long int dp[MAX][4];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long int a;
		scanf("%lld", &a);
		v.push_back(a);
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 4; j++) {
			dp[i][j] = LLONG_MIN;
		}
	}
	dp[0][0] = 0;
	long long int debris = 0;
	long long int form = 0;
	for (int i = 0; i < v.size(); i++) {
		long long int ava = min(debris, v[i] / 2);
		form += ava;
		debris -= ava;
		v[i] -= ava * 2LL;
		form += v[i] / 3;
		v[i] %= 3;
		debris += v[i];
	}
	printf("%lld\n", form);
	return 0;
}