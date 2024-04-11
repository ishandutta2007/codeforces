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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;
const double EPS = 1e-8;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;

const int SIZE = 2097152;

int v[SIZE];
int add[SIZE];
int l[SIZE];
int r[SIZE];

class Segment_Tree {
	int ret;
	inline void Left(int place) {
		if (place >= SIZE >> 1) {
			l[place] = place - (SIZE >> 1);
			return;
		}
		Left(place<<1);
		Left((place<<1)|1);
		l[place] = l[place << 1];
		return;
	}
	inline void Right(int place) {
		if (place >= (SIZE>>1)) {
			r[place] = place - (SIZE>>1);
			return;
		}
		Right(place <<1);
		Right((place <<1) | 1);
		r[place] = r[(place <<1) | 1];
		return;
	}
	inline int Update(int place) {
		if (place >= SIZE>>1) {
			return v[place];
		}
		v[place] = max(Update(place <<1), Update((place << 1) | 1));
		return v[place];
	}
	inline void Add(int a, int b, int num, int place) {
		if (l[place] >= a && r[place] <= b) {
			add[place] += num;
			return;
		}
		if (l[place] > b || r[place] < a)return;
		add[place<<1] += add[place];
		add[(place<<1)|1] += add[place];
		add[place] = 0;
		Add(a, b, num, place<<1);
		Add(a, b, num, (place<<1)|1);
		v[place] = max(v[place<<1] + add[place<<1], v[(place<<1)|1] + add[(place<<1)|1]);
		return;
	}
	inline void RMQ(int a, int b, int place) {
		if (l[place] >= a && r[place] <= b) {
			ret = max(ret, v[place] + add[place]);
			return;
		}
		if (l[place]>b || r[place]<a) return;
		add[place<<1] += add[place];
		add[(place<<1)|1] += add[place];
		add[place] = 0;
		RMQ(a, b, place<<1);
		RMQ(a, b, (place<<1)|1);
		v[place] = max(v[place<<1] + add[place<<1], v[(place<<1)|1] + add[(place<<1)|1]);
		return;
	}
public:
	Segment_Tree() {
		Left(1);
		Right(1);
	}
	inline void Insert(int place, int num, bool update) {
		place += SIZE>>1;
		v[place] = num;
		if (!update)return;
		place /= 2;
		while (place) {
			v[place] = max(v[place<<1], v[(place<<1)|1]);
			place >>= 1;
		}
	}
	inline void Add(int a, int b, int num) {
		Add(a, b, num, 1);
	}
	inline void Init() {
		Update(1);
	}
	inline int RMQ(int a, int b) {
		ret = INT_MIN/2;
		RMQ(a, b, 1);
		return ret;
	}
};

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
 
	scanf("%d %d", &N, &M);
	vector<int>v(N);
	for (int i = 0; i < N; i++)scanf("%d", &v[i]);
	vector<int>w(M);
	for (int i = 0; i < M; i++) scanf("%d", &w[i]);
	scanf("%d", &K);
	Segment_Tree sg;
	for (int i = 0; i < N; i++) {
		sg.Add(1, v[i], 1);
	}
	for (int i = 0; i < M; i++) {
		sg.Add(1, w[i], -1);
	}
	for (int loop = 0; loop < K; loop++) {
		scanf("%d %d %d", &L, &R, &H);
		R--;
		if (L == 1) {
			if (v[R] > H) {
				sg.Add(H + 1, v[R], -1);
			}
			else if(v[R]<H) {
				sg.Add(v[R] + 1, H, 1);
			}
			v[R] = H;
		}
		else {
			if (w[R] > H) {
				sg.Add(H + 1, w[R], 1);
			}
			else if (w[R] < H) {
				sg.Add(w[R] + 1, H, -1);
			}
			w[R] = H;
		}
		L = 0, R = 1000001;
		while (R - L > 1) {
			int mid = (R + L) >> 1;
			if (sg.RMQ(mid, 1000000) > 0) {
				L = mid;
			}
			else R = mid;
		}
		if (!L)L = -1;
		cout << L << "\n";
	}
}