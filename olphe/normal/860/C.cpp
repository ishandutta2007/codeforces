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
		if (l[place] >= a&&r[place] <= b) {
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
		if (min) {
			v.resize(num, LLONG_MAX);
			is_min = true;
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

	cin >> N;
	vector<string>s(N);
	vector<int>flag(N);
	Segment_Tree sg(N, true);
	for (int i = 0; i < N; i++) {
		cin >> s[i] >> flag[i];
		if (flag[i]) {
			M++;
		}
	}
	for (int i = 1; i <= N; i++) {
		sg.Insert(i, i, false);
	}
	queue<int>QL;
	queue<int>QR;
	queue<int>QQ;
	bool add = true;
	for (int i = 0; i < N; i++) {
		bool fla = true;
		for (auto j : s[i]) {
			if (j<'0' || j>'9') {
				fla = false;
				break;
			}
		}
		if (!fla) {
			QQ.push(i);
			add = false;
			continue;
		}
		if (s[i][0] == '0') {
			QQ.push(i);
			add = false;
			continue;
		}
		long long int box = 0;
		for (auto j : s[i]) {
			box *= 10;
			box += (j - '0');
		}
		if (box > N) {
			add = false;
			QQ.push(i);
			continue;
		}
		if (box <= M) {
			L++;
		}
		else {
			R++;
		}

		if (box <= M && !flag[i]) {
			QL.push(box);
		}
		else if(box>M&&flag[i]) {
			QR.push(box);
		}

		sg.Insert(box, INT_MAX + box, false);
	}
	sg.TopDown();
	if (add&&QR.empty() && QL.empty()) {
		cout << "0\n";
		return 0;
	}
	cout << QR.size() + QL.size() + QQ.size() + add << endl;
	if (add) {
		if (R) {
			cout << "move " << QR.front() << " " << "200000\n";
			sg.Insert(QR.front(), QR.front(), true);
			QR.pop();
			R--;
		}
		else {
			cout << "move " << QL.front() << " " << "200000\n";
			sg.Insert(QL.front(), QL.front(), true);
			QL.pop();
			L--;
		}
	}
	while (!QR.empty() || !QL.empty()) {
		if (M != L&&!QR.empty()) {
			R--;
			L++;
			long long int box = QR.front();
			QR.pop();
			sg.Insert(box, box, true);
			long long int bag = sg.RMQ(1, M);
			sg.Insert(bag, bag + INT_MAX, true);
			cout << "move " << box << " " << bag << endl;
			
		}
		else if(N-M!=R&&!QL.empty()){
			R++;
			L--;
			long long  int box = QL.front();
			QL.pop();
			sg.Insert(box, box, true);
			long long int bag = sg.RMQ(M + 1, N);
			sg.Insert(bag, bag + INT_MAX, true);
			cout << "move " << box << " " << bag << endl;
		}
	}
	while (!QQ.empty()) {
		long long int box = QQ.front();
		QQ.pop();
		if (flag[box]) {
			long long int bag = sg.RMQ(1, M);
			sg.Insert(bag, bag + INT_MAX, true);
			cout << "move " << s[box] << " " << bag << endl;
		}
		else {
			long long int bag = sg.RMQ(M + 1, N);
			sg.Insert(bag, bag + INT_MAX, true);
			cout << "move " << s[box] << " " << bag << endl;
		}
	}
	if (add) {
		cout << "move 200000 " << sg.RMQ(1, N) << endl;
	}
	return 0;
}