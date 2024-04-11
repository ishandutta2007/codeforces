#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>v(2*N+1);
	for (int i = 1; i <= 2*N;i++)cin >> v[i];
	vector<int>p(2*N+1);
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		p[L] = R;
		p[R] = L;
	}
	cin >> K;
	vector<int>used(2*N + 1);
	K &= 1;
	int nx = -1;
	for (int i = 1; i <= N * 2; i++) {
		if ((i & 1) == K) {
			if (nx != -1) {
				used[nx]++;
				cout << nx << endl;
			}
			else {
				bool flag = true;
				for (int j = 1; j <= 2 * N; j++) {
					if (p[j] && !used[p[j]]) {
						if (v[j] > v[p[j]]) {
							cout << j << endl;
							flag = false;
							used[j]++;
							break;
						}
						else {
							cout << p[j] << endl;
							flag = false;
							used[p[j]]++;
							break;
						}
					}
				}
				if (flag) {
					for (int j = 1; j <= 2 * N; j++) {
						if (!used[j]) {
							if (nx == -1)nx = j;
							else if (v[nx] < v[j])nx = j;
						}
					}
					cout << nx << endl;
					used[nx]++;
				}
			}
			nx = -1;
		}
		else {
			cin >> H;
			used[H]++;
			if (p[H] && !used[p[H]])nx = p[H];
		}
	}
}