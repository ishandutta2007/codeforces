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
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<long long int>s(N);
	vector<long long int>a(N);
	vector<long long int>b(N);
	vector<pair<long long int, long long int>>v(N);
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> s[i] >> a[i] >> b[i];
		R += s[i];
		ans += a[i] * s[i];
		v[i] = { b[i] - a[i],s[i] };
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (auto i : v) {
		if (i.first > 0) {
			M += i.second;
		}
	}
	L = M;
	M /= K;
	M *= K;
	long long int box = 0;
	long long int bag = 0;
	for (auto i : v) {
		if (box + i.second <= M) {
			bag += i.first*i.second;
			box += i.second;
		}
		else {
			bag += i.first*(M - box);
			break;
		}
	}
	long long int s_box = 0;
	long long int s_bag = 0;
	M += K;
	if (R%K) {
		H = K - R%K;
	}
	if (M - H <= L &&L <= M) {
		M = L;
	}
	else {
		M -= H;
	}
	for (auto i : v) {
		if (s_box + i.second <= M) {
			s_box += i.second;
			s_bag += i.first*i.second;
		}
		else {
			s_bag += i.first*(M - s_box);
			break;
		}
	}
	//cout << ans << endl;
	//cout << bag << " " << s_bag << endl;
	cout << ans + max(bag, s_bag) << endl;
	return 0;
}