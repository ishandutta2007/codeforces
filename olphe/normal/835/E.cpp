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

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

long long int N, M, K, Q, W, H, L, R;
long long int ans;



int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	bool bit[20] = {};
	long long int xnum[2][2] = {};
	xnum[0][0] = 0;
	xnum[0][1] = K;
	xnum[1][0] = M;
	xnum[1][1] = K^M;
	int num[] = { 1,2,4,8,16,32,64,128,256,512,1024 };
	for (int i = 1; i <= 10; i++) {
		list<int>l;
		for (int j = 1; j <= N; j++) {
			if (j%num[i] >= num[i] / 2) {
				l.push_back(j);
			}
		}
		if (l.empty())continue;
		cout << "?";
		cout << " " << l.size();
		for (auto j : l)cout << " " << j;
		cout << endl;
		long long int box;
		cin >> box;
		if (box == xnum[0][1] || box == xnum[1][1])bit[i - 1] = true;
	}
	int twoor = 0;
	for (int i = 0; i < 10; i++) {
		if (bit[i])twoor += num[i];
	}
	int mbit = 100;
	for(int i=0;i<10;i++){
		if (bit[i]) {
			mbit = i;
			break;
		}
	}
	int ret = 0;
	ret = num[mbit];
	for (int i = 0; i < 10; i++) {
		if (i == mbit)continue;
		list<int>l;
		for (int j = 1; j <= N; j++) {
			if (j%num[mbit + 1] >= num[mbit] && j%num[i + 1] >= num[i]) {
				l.push_back(j);
			}
		}
		if (l.empty())continue;
		cout << "?";
		cout << " " << l.size();
		for (auto j : l)cout << " " << j;
		cout << endl;
		long long int box;
		cin >> box;
		if (box == xnum[0][1] || box == xnum[1][1])ret += num[i];
	}
	//for (int i = 0; i < 10; i++)if (bit[i])cout << num[i] << endl;
	for (int i = 1; i <= N; i++) {
		if ((ret^i) == twoor) {
			if (ret < i)swap(ret, i);
			cout << "! " << i << " " << ret << " " << endl;
			return 0;
		}
	}
	return 0;
}