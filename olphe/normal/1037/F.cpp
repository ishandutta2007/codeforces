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

long long int N, M, K, H, W, L, R;

class Segment_Tree {
	vector<long long int>v;
	vector<int>l;
	vector<int>r;
	int num;
	long long int ret;
	bool is_min;
	long long int Update(int place) {
		if (place >= v.size() / 2) {
			return v[place];
		}
		if (is_min) {
			v[place] = min(Update(place * 2), Update(place * 2 + 1));
			return v[place];
		}
		v[place] = max(Update(place * 2), Update(place * 2 + 1));
		return v[place];
	}
	void RMQ(int a, int b, int place) {
		if (l[place] >= a && r[place] <= b) {
			if (is_min)ret = min(ret, v[place]);
			else ret = max(ret, v[place]);
			return;
		}
		if (l[place]>b || r[place]<a) return;
		RMQ(a, b, place * 2);
		RMQ(a, b, place * 2 + 1);
		return;
	}
public:
	void Left(int place) {
		if (place >= v.size() / 2) {
			l[place] = place - v.size() / 2;
			return;
		}
		Left(place * 2);
		Left(place * 2 + 1);
		l[place] = l[place * 2];
		return;
	}
	void Right(int place) {
		if (place >= v.size() / 2) {
			r[place] = place - v.size() / 2;
			return;
		}
		Right(place * 2);
		Right(place * 2 + 1);
		r[place] = r[place * 2 + 1];
		return;
	}
	Segment_Tree(int n, bool min) {
		n++;
		num = 1;
		while (num < n * 2) {
			num *= 2;
		}
		l.resize(num);
		r.resize(num);
		is_min = min;
		if (min) {
			v.resize(num, LLONG_MAX);
		}
		else v.resize(num, LLONG_MIN);
		Left(1);
		Right(1);
	}
	void Insert(int place, long long int num, bool update) {
		place += v.size() / 2;
		v[place] = num;
		if (!update)return;
		place /= 2;
		while (place) {
			if (is_min)v[place] = min(v[place * 2], v[place * 2 + 1]);
			else v[place] = max(v[place * 2], v[place * 2 + 1]);
			place /= 2;
		}
	}
	void TopDown() {
		Update(1);
	}
	long long int RMQ(int a, int b) {
		if (is_min)ret = LLONG_MAX;
		else ret = LLONG_MIN;
		RMQ(a, b, 1);
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<int>v(N + 1);
	vector<pair<long long int, int>>w(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		w[i] = { v[i],i };
	}
	sort(w.begin(), w.end());
	reverse(w.begin(), w.end());
	Segment_Tree Msg(N + 2, false);
	Segment_Tree msg(N + 2, true);
	Msg.Insert(0, 0, true);
	Msg.Insert(N + 1, N + 1, true);
	msg.Insert(0, 0, true);
	msg.Insert(N + 1, N + 1, true);
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		L = w[i].second - Msg.RMQ(0, w[i].second) - 1;
		R = msg.RMQ(w[i].second, N + 1) - w[i].second - 1;
		if (R < L)swap(L, R);
		long long int f = 1 + L / (K - 1);
		long long int turn = 1;
		long long int box = 0;
		long long int bag = 1;
		if (f > turn) {
			box += (2 * K + (K - 1)*(f - turn - 1))*(f - turn) / 2;
			box %= MOD;
			L -= (f - turn)*(K - 1);
			R -= (f - turn)*(K - 1);
			
			bag += (f - turn)*(K - 1);
			turn = f;
		}
		L -= (K - 1);
		R -= (K - 1);
		bag += K - 1;
		bag += L;
		if (R <= 0) {
			bag += R;
			bag = max(bag, 0LL);
		}
		box += max(0LL,bag);
		box %= MOD;
		//**/	cout << w[i].first << " " << bag << "box " << box << "R " << R << endl;
		if (bag <= 0) {
			ans += box * w[i].first;
			ans %= MOD;
	//**/		cout << w[i].first << " " << box <<" 0"<< endl;
			msg.Insert(w[i].second, w[i].second, true);
			Msg.Insert(w[i].second, w[i].second, true);
			continue;
		}
		if (R>0) {
			long long int nx = R / (K - 1);
			box += nx * bag;
			box %= MOD;
			R -= nx * (K - 1);
			R -= K - 1;
			bag += R;
			box += max(0LL, bag);
			box %= MOD;
			if (bag <= 0) {
				ans += box * w[i].first;
				ans %= MOD;
		//**/		cout << w[i].first << " " << box <<" 1"<< endl;
				msg.Insert(w[i].second, w[i].second, true);
				Msg.Insert(w[i].second, w[i].second, true);
				continue;
			}
		}
		long long int nx = bag / (K - 1);
		if (nx) {
			box += (bag - (K - 1) + bag % (K - 1))*nx / 2;
			box %= MOD;
		}
		ans += box * w[i].first;
		ans %= MOD;
	//**/	cout << w[i].first << " " << box <<" 2"<< endl;
		msg.Insert(w[i].second, w[i].second, true);
		Msg.Insert(w[i].second, w[i].second, true);
	}
	cout << ans << endl;
	return 0;
}