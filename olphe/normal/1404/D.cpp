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

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int twin(int a) {
	if (a <= N)return a + N;
	else return a - N;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	if (N % 2 == 0) {
		cout << "First" << endl;
		for (int i = 1; i <= 2 * N; i++) {
			if (i > 1)cout << " ";
			if (i <= N)cout << i;
			else cout << i - N;
		}
		cout << endl;
		cin >> N;
		return 0;
	}
	else {
		cout << "Second" << endl;
		vector<int>v(N * 2 + 1);
		vector<vector<int>>box(N + 1);
		for (int i = 1; i <= N * 2; i++) {
			cin >> v[i];
			box[v[i]].push_back(i);
		}
		vector<int>used(N + 1);
		vector<int>sz(N + 1);
		long long int sum = 0;
		vector<int>ans(N * 2 + 1);
		vector<int>p(N + 1);
		for (int i = 1; i <= N; i++) {
			if (used[i])continue;
			used[i] = 1;
			p[i] = i;
			sz[i]++;
			sum += box[i][0];
			ans[box[i][0]] = 1;
			queue<int>Q;
			int nx = v[twin(box[i][1])];
			int bef = box[i][1];
			if (nx != i) {
				Q.push(nx);
				used[nx] = 1;
				p[nx] = i;
			}
			while (!Q.empty()) {
				int cn = Q.front();

				sz[i]++;
				Q.pop();
				if (box[cn][0] == twin(bef)) {
					sum += box[cn][0];
					ans[box[cn][0]] = 1;
					nx = v[twin(box[cn][1])];
					bef = box[cn][1];
				}
				else {
					sum += box[cn][1];
					ans[box[cn][1]] = 1;
					nx = v[twin(box[cn][0])];
					bef = box[cn][0];
				}
				if (!used[nx]) {
					Q.push(nx);
					used[nx] = 1;
					p[nx] = i;
				}
			}
		//	cout << i << " " << sz[i] << endl;
		}
		//	cout << sum << endl;
		if (sum % (2 * N)) {
			for (int i = 1; i <= N; i++) {
				if (sz[i] % 2 == 0) continue;
				for (int j = 1; j <= N; j++) {
			//		cout << j << " p " << p[j] << endl;
					if (p[j] == i) {
						if (ans[box[j][0]]) {
							sum -= box[j][0];
							sum += box[j][1];
							ans[box[j][0]] = 0;
							ans[box[j][1]] = 1;
						}
						else {
							sum -= box[j][1];
							sum += box[j][0];
							ans[box[j][1]] = 0;
							ans[box[j][0]] = 1;
						}
					}
				}
				break;
			}
		}
		//	cout << sum << endl;
		vector<int>ret(N + 1);
		for (int i = 1; i <= N * 2; i++) {
			if (ans[i])ret[v[i]] = i;
		}
		for (int i = 1; i <= N; i++) {
			if (i > 1)cout << " ";
			cout << ret[i];
		}
		cout << endl;
		cin >> N;
		return 0;
	}
}