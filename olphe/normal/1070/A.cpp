#include "iostream"
#include "vector"
#include "queue"
#include "deque"
#include "string"

using namespace std;

const long long int MOD = 1000000007;

int N, M;
int dis[500][5001][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	if (N == 1) {
		while (M) {
			if (M % 9) {
				cout << M % 9;
				M -= M % 9;
			}
			else {
				cout << 9;
				M -= 9;
			}
		}
		cout << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			for (int k = 0; k < 10; k++)dis[i][j][k] = MOD;
		}
	}
	dis[1][1][1] = 1;
	deque<int>Q;
	int f = 100000;
	int s = 10;
	Q.push_back(f + s + 1);
	while (!Q.empty()) {
		auto cn = Q.front();
		//	cout << cn << endl;
		Q.pop_front();
		if (cn % 10 < 9 && (cn / 10) % 10000<M) {
			if (dis[(cn / f + 1) % N][(cn / 10) % 10000 + 1][cn % 10 + 1] > dis[cn / f][(cn / 10) % 10000][cn % 10]) {
				dis[(cn / f + 1) % N][(cn / 10) % 10000 + 1][cn % 10 + 1] = dis[cn / f][(cn / 10) % 10000][cn % 10];
				Q.push_front(((cn / f + 1) % N)*f + ((cn / 10) % 10000 + 1)*s + (cn % 10 + 1));
			}
		}
		if (dis[(cn / f * 10) % N][(cn / 10) % 10000][0] > dis[cn / f][(cn / 10) % 10000][cn % 10] + 1) {
			dis[(cn / f * 10) % N][(cn / 10) % 10000][0] = dis[cn / f][(cn / 10) % 10000][cn % 10] + 1;
			Q.push_back(((cn / f * 10) % N)*f + ((cn / 10) % 10000)*s);
		}
	}
	vector<vector<int>>edge(N);
	for (int i = 0; i < N; i++) {
		edge[(i * 10) % N].push_back(i);
	}
	int box = MOD;
	for (int i = 0; i < 10; i++) {
		box = min(box, dis[0][M][i]);
	}
	//cout << box << endl;
	if (box == MOD) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < 10; i++) {
		if (dis[0][M][i] == box) {
			dis[0][M][i] *= -1;
			Q.push_front(M*s + i);
		}
	}
	while (!Q.empty()) {
		auto cn = Q.front();
		Q.pop_front();
		if (cn % 10) {
			if (dis[cn / f ? cn / f - 1 : N - 1][(cn / 10) % 10000 - 1][cn % 10 - 1]>0) {
				Q.push_back((cn / f ? cn / f - 1 : N - 1)*f + ((cn / 10) % 10000 - 1)*s + (cn % 10 - 1));
				dis[cn / f ? cn / f - 1 : N - 1][(cn / 10) % 10000 - 1][cn % 10 - 1] *= -1;
			}
		}
		else {
			for (auto i : edge[cn / f]) {
				for (int j = 0; j < 10; j++) {
					if (abs(dis[i][(cn / 10) % 10000][j]) == abs(dis[cn / f][(cn / 10) % 10000][cn % 10]) - 1) {
						if (dis[i][(cn / 10) % 10000][j] > 0) {
							Q.push_back(i*f + ((cn / 10) % 10000)*s + j);
							dis[i][(cn / 10) % 10000][j] *= -1;
						}
					}
				}
			}
		}
	}
	string ret = "1";
	int a = 1;
	int b = 1;
	int c = 1;
	while (a || b < M) {
		//cout << a << " " << b << " " << c << endl;
		if (dis[(a * 10) % N][b][0]<0&&abs(dis[(a*10)%N][b][0])>abs(dis[a][b][c])) {
			ret.push_back('0');
			a *= 10;
			a %= N;
			c = 0;
		}
		else {
			a++;
			a %= N;
			b++;
			c++;
			ret[ret.size() - 1]++;
		}
	}
	cout << ret << endl;
	return 0;
}