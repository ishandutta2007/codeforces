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

long long int score(long long int num, long long int div) {
	long long int ret = (num / div)*(num / div) * div;
	ret -= (num / div)*(num / div)*(num%div);
	ret += (num / div + 1)*(num / div + 1)*(num%div);
	return ret;
}

struct Node {
	long long int num, div;
	long long int gain;
	Node(const int n, const int d) :num(n), div(d) {
		gain = score(num, div) - score(num, div + 1);
	}
	bool operator<(const Node&n)const {
		return gain < n.gain;	
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<long long int>v(N);
	long long int ans = 0;
	priority_queue<Node>PQ;
	for (auto &i : v) {
		cin >> i;
		ans += i * i;
		if (i > 1)	PQ.push(Node(i, 1));
	}
	while (N < K) {
		N++;
		auto box = PQ.top();
	//	cout << box.num << " " << box.div << " " << box.gain << endl;
		PQ.pop();
		ans -= box.gain;
		if (box.num > box.div)PQ.push(Node(box.num, box.div + 1));
	}
	cout << ans << endl;
}