#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

#define mp(a,b) make_pair(a,b)
#define add(a,b) (((ll)a+b)%mod)
#define sub(a,b) (((ll)a-b)%mod)
#define mul(a,b) ((ll)a*b%mod)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int dyn1[3400][3400]; //problem on the prefix of n
int dyn2[3400][3400]; //dyn1 + additional carry assumed
int dyn3[3400][3400]; //problem on the prefix of n-1
int dyn4[3400][3400]; //dyn3 + carry
int num[3400];
int len = 0;
char buf[1500];
int quot[3400];
int qp = 0;

const int mod = 1000000007;

inline void addr(int &a, int b) {
	a = ((ll)a + b) % mod;
}

int main() {
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int p, alp;
	scanf("%d %d", &p, &alp);
	scanf("%s", buf);
	int n = strlen(buf);
	ll tmp = 0;
	for (int i = 0; i < n; i++) {
		quot[i] = buf[i] - '0';
	}
	
	while (n > 0) {
		int cnt = 0;
		qp = 0;
		tmp = 0;
		for (int i = 0; i < n; i++) {
			tmp *= 10;
			tmp += (quot[i]);
			if (qp == 0) {
				if (tmp / p != 0) {
					cnt++;
					quot[qp++] = tmp / p;
				}
			}
			else {
				quot[qp++] = tmp / p;
				cnt++;
			}
			tmp = tmp%p;
		}
		num[len++] = tmp;
		n = cnt;
	}
	for (int i = 0; i < len / 2; i++) swap(num[i],num[len-1-i]);
	if (alp > len) {
		puts("0");
		return 0;
	}
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j <= alp; j++) {
			if (i == 0) {
				if (j == 0) {
					dyn1[i][j] = 1;
				}
				else {
					dyn1[i][j] = 0;
				}
				dyn2[i][j] = 0;
				dyn3[i][j] = 0;
				dyn4[i][j] = 0;
			}
			else {
				int N = num[i - 1];
				int tot = mul(p, p);
				int jj = max(j - 1, 0);
				//dyn1
				int n1 = (((ll)(N + 1))*(N + 2) / 2)%mod; //no carry no overflow
				int n2 = (((ll)(p + 1)*p) / 2) % mod; //total no carry
				int n3;	//carry + overflow
				if (N >= p - 2) n3 = 0;
				else {
					int hh = p - 2 - N;
					n3 = ((ll)(hh + 1)*hh / 2) % mod;
				}
				int n4 = sub(tot, add(n2, n3)); //carry, no overflow
				ll bb;
				bb = (ll)n1*dyn1[i - 1][j] + (ll)(n2 - n1)*dyn3[i - 1][j] + (ll)n4*dyn2[i - 1][jj] + (ll)n3*dyn4[i - 1][jj];
				dyn1[i][j] = ((ll)dyn1[i][j] + bb) % mod;
				
				
				//dyn2
				n1 = (ll)N*(N + 1) / 2 % mod;
				int n22 = (ll)p*(p - 1) / 2 % mod;
				int hh = p - 1 - N;
				n3 = (ll)(hh + 1)*hh / 2 % mod;
				n4 = sub(tot, add(n22, n3));
				bb = (ll)n1*dyn1[i - 1][j] + (ll)(n22 - n1)*dyn3[i - 1][j] + (ll)n4*dyn2[i - 1][jj] + (ll)n3*dyn4[i - 1][jj];
				dyn2[i][j] = ((ll)dyn2[i][j] + bb) % mod;

				//dyn3
				n4 = sub(tot, add(n2, n3));
				bb = (ll)n1*dyn1[i - 1][j] + (ll)(n2 - n1)*dyn3[i - 1][j] + (ll)n4*dyn2[i - 1][jj] + (ll)n3*dyn4[i - 1][jj];
				dyn3[i][j] = ((ll)dyn3[i][j] + bb) % mod;
			
				//dyn4
				n1 = (ll)N*(N - 1) / 2 % mod;
				hh = p - N;
				n3 = (ll)(hh + 1)*hh / 2 % mod;
				n4 = sub(tot, add(n22, n3));
				bb = (ll)n1*dyn1[i - 1][j] + (ll)(n22 - n1)*dyn3[i - 1][j] + (ll)n4*dyn2[i - 1][jj] + (ll)n3*dyn4[i - 1][jj];
				dyn4[i][j] = ((ll)dyn4[i][j] + bb) % mod;


			}
		}
	}
	if (dyn1[len][alp] < 0) dyn1[len][alp] += mod;
	printf("%d\n", dyn1[len][alp]);
	return 0;
}