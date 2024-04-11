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
constexpr long  double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

class Segment_Tree {
	vector<long long int>v;
	vector<long long int>add;
	vector<long long int>modi;
	vector<int>l;
	vector<int>r;
	int num;
	long long int ret;
	bool is_min;
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
	void Modify(int a, int b, long long int num, int place) {
		if (l[place] >= a && r[place] <= b) {
			modi[place] = num;
			v[place] = num;
			add[place] = 0;
			return;
		}
		if (l[place] > b || r[place] < a)return;
		if (modi[place] != LLONG_MAX) {
			modi[place * 2] = modi[place * 2 + 1] = modi[place];
			v[place * 2] = v[place * 2 + 1] = modi[place];
			add[place * 2] = add[place * 2 + 1] = 0;
			modi[place] = LLONG_MAX;
		}
		add[place * 2] += add[place];
		add[place * 2 + 1] += add[place];
		add[place] = 0;
		Modify(a, b, num, place * 2);
		Modify(a, b, num, place * 2 + 1);
		if (is_min)v[place] = min(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		else v[place] = max(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		return;
	}
	void Add(int a, int b, long long int num, int place) {
		if (l[place] >= a && r[place] <= b) {
			if (modi[place] != LLONG_MAX) {
				if (place * 2 < v.size()) {
					modi[place * 2] = modi[place * 2 + 1] = modi[place];
					v[place * 2] = v[place * 2 + 1] = modi[place];
					add[place * 2] = add[place * 2 + 1] = 0;
				}
				modi[place] = LLONG_MAX;
			}
			add[place] += num;
			return;
		}
		if (l[place] > b || r[place] < a)return;
		if (modi[place] != LLONG_MAX) {
			modi[place * 2] = modi[place * 2 + 1] = modi[place];
			v[place * 2] = v[place * 2 + 1] = modi[place];
			add[place * 2] = add[place * 2 + 1] = 0;
			modi[place] = LLONG_MAX;
		}
		add[place * 2] += add[place];
		add[place * 2 + 1] += add[place];
		add[place] = 0;
		Add(a, b, num, place * 2);
		Add(a, b, num, place * 2 + 1);
		if (is_min)v[place] = min(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		else v[place] = max(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		return;
	}
	void RMQ(int a, int b, int place) {
		if (l[place] >= a && r[place] <= b) {
			if (modi[place] != LLONG_MAX) {
				if (place * 2 < v.size()) {
					modi[place * 2] = modi[place * 2 + 1] = modi[place];
					v[place * 2] = v[place * 2 + 1] = modi[place];
					add[place * 2] = add[place * 2 + 1] = 0;
				}
				modi[place] = LLONG_MAX;
			}
			if (is_min)ret = min(ret, v[place] + add[place]);
			else ret = max(ret, v[place] + add[place]);
			return;
		}
		if (l[place]>b || r[place]<a) return;
		if (modi[place] != LLONG_MAX) {
			modi[place * 2] = modi[place * 2 + 1] = modi[place];
			v[place * 2] = v[place * 2 + 1] = modi[place];
			add[place * 2] = add[place * 2 + 1] = 0;
			modi[place] = LLONG_MAX;
		}
		add[place * 2] += add[place];
		add[place * 2 + 1] += add[place];
		add[place] = 0;
		RMQ(a, b, place * 2);
		RMQ(a, b, place * 2 + 1);
		if (is_min)v[place] = min(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		else v[place] = max(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		return;
	}
public:
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
			v.resize(num, MOD*MOD);
		}
		else v.resize(num, -MOD * MOD);
		add.resize(num, 0);
		modi.resize(num, MOD*MOD);
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
	void Modify(int a, int b, long long int num) {
		Modify(a, b, num, 1);
	}
	void Add(int a, int b, long long int num) {
		Add(a, b, num, 1);
	}
	void Init() {
		Update(1);
	}
	long long int RMQ(int a, int b) {
		if (is_min)ret = LLONG_MAX;
		else ret = LLONG_MIN/10;
		RMQ(a, b, 1);
		return ret;
	}
};

struct Enemy {
	int dif, atk, coin;
	Enemy(const int d, const int a, const int c) {
		dif = d, atk = a, coin = c;
	}
	bool operator<(const Enemy&e)const {
		return dif < e.dif;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<pair<int, int>>weapon(N);
	vector<pair<int, int>>guard(M);
	map<int, int>mp;
	for (auto &i : weapon)cin >> i.first >> i.second;
	sort(weapon.begin(), weapon.end());
	for (auto &i : guard) {
		cin >> i.first >> i.second;
		i.second *= -1;
		mp[i.first] = 0;
	}
	sort(guard.begin(), guard.end());
	vector<Enemy>enemy(K,Enemy(0,0,0));
	for (auto &i : enemy) {
		cin >> i.dif >> i.atk >> i.coin;
		mp[i.atk] = 0;
	}
	sort(enemy.begin(), enemy.end());
	int cnt = 0;
	for (auto &i : mp) {
		i.second = cnt++;
	}
	for (auto &i : guard)i.first = mp[i.first];
	for (auto &i : enemy)i.atk = mp[i.atk];
	long long int ans = -MOD*MOD;
	Segment_Tree sg(cnt, false);
	sg.Modify(0, cnt - 1, -MOD * MOD);
	for (auto i : guard) {
		sg.Modify(i.first, i.first, i.second);
	}
	int index = 0;
	for (auto i : weapon) {
		while (index < K&&enemy[index].dif < i.first) {
			sg.Add(enemy[index].atk + 1, cnt - 1, enemy[index].coin);
			index++;
		}
		ans = max(ans, sg.RMQ(0, cnt - 1) - i.second);
	}
	cout << ans << endl;
}