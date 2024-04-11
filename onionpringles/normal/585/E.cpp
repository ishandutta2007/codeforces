#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <vector>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int Big = 10000001;
const int mod = 1000000007;

int moeb[Big];
int is_prime[Big];
int occurs[Big];

inline void mul(int &a, int b) {
	a = (long long)a*b%mod;
}
inline void add(int &a, int b) {
	a = ((long long)a + b) % mod;
}

int pow(int n) {
	if (n == 0) return 1;
	int tmp = pow(n / 2);
	mul(tmp, tmp);
	if (n % 2) mul(tmp, 2);
	return tmp;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		occurs[x]++;
	}
	for (int i = 0; i < Big; i++) {
		moeb[i] = is_prime[i] = 1;
	}
	for (int i = 2; i < Big; i++) {
		if (!is_prime[i]) continue;
		for (int j = i; j < Big;j+=i) {
			is_prime[j] = 0;
			moeb[j] *= -1;
		}
		if (i < 10000) {
			for (int j = i*i; j < Big; j += i*i) {
				moeb[j] = 0;
			}
		}
	}
	int res = 0;
	for (int i = 2; i < Big; i++) {
		if (!moeb[i]) continue;
		int cnt=0;
		for (int j = i; j < Big; j += i) {
			cnt += occurs[j];
		}
		int tmp = n - cnt;
		mul(tmp, (pow(cnt) - 1));
		tmp *= moeb[i];
		while (tmp < 0) tmp += mod;
		add(res, tmp);
	}
	res = -res;
	if (res < 0) res += mod;
	printf("%d\n", res);
}