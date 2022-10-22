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
#include "cassert"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>num(N * 2 + 1);
	for (int i = 3; i <= N * 2; i++) {
		num[i] = i * (i - 1)*(i - 2) / 6;
	}
	vector<int>a(N + 1);
	vector<int>b(N + 1);
	cin >> a[0] >> b[0];
	vector<int>fst(N + 1, -1);
	vector<int>ed(N + 1, -1);
	for (int i = 1; i <= 3; i++) {
		cout << "+ " << i << endl;
		cin >> a[i] >> b[i];
	}
	cout << "+ 1" << endl;
	cin >> a[4] >> b[4];
	for (int i = 4; i < N; i++) {
		cout << "+ " << i << endl;
		cin >> a[i + 1] >> b[i + 1];
	}
	if (b[2] == b[1]) {
		fst[3] = 0;
		ed[3] = 1;
	}
	else if (a[3] == a[2]) {
		fst[3] = 1, ed[3] = 2;
	}
	else {
		for (int i = 3; i <= N * 2; i++) {
			//cout << " 3 " << i << endl;
			//cout << num[i] - num[i - 1] << endl;
			if (a[3] - a[2] == num[i]-num[i-1]) {
				ed[3] = i;
				fst[3] = i - 1;
				break;
			}
		}
	}
	for (int i = 2; i <= N * 2; i++) {
		if (a[4] - a[3] == num[i]-num[i-1]) {
			ed[1] = i;
			fst[1] = i - 2;
			break;
		}
	}
	ed[2] = (b[4] - b[3]) / ed[3];
	fst[2] = ed[2] - 1;
	if (N == 4) {
		fst[4] = (b[3] - (b[2] + (fst[1] + 1)*(fst[2] + 1))) / ed[2];
		ed[4] = fst[4] + 1;
	}
	else {
		if (b[3] - b[2] == (ed[1]-1) * ed[2]) {
			ed[4] = 1;
			fst[4] = 0;
		}
		else {
			int i = 4;
			for (int j = 2; j <= N * 2; j++) {
				if (a[i + 1] - a[i] == num[j] - num[j - 1]) {
					ed[i] = j;
					fst[i] = j - 1;
					break;
				}
			}
		}
	}
	for (int i = 5; i < N; i++) {
		if (b[i] - b[i - 1] == ed[i - 3] * ed[i - 2]) {
			ed[i] = 1;
			fst[i] = 0;
		}
		else{
			for (int j = 2; j <= N * 2; j++) {
				if (a[i + 1] - a[i] == num[j]-num[j-1]) {
					ed[i] = j;
					fst[i] = j - 1;
					break;
				}
			}
		}
	}
	if (N > 4) {
	//	cout<<b[N]<<" "<<b[N-1]<<" "<<ed[N-3]<<" "<<
		fst[N] = (b[N] - b[N - 1] - ed[N - 3] * ed[N - 2]) / ed[N - 2];
	}
	cout << "!";
	for (int i = 1; i <= N; i++) {
		cout << " " << fst[i];
	}
	cout << endl;
}