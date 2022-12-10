//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define L first
#define R second

typedef pair<int, int> pii;

const int maxn = 2020;
set<pii> s;
map<int, int> mp;
int n, m;
int fi[maxn],
	se[maxn];
int power[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n + n; i++) {
		cin >> power[i];
		s.insert(MP(-power[i], i));
		mp[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		cin >> fi[i] >> se[i], fi[i]--, se[i]--;
		mp[fi[i]] = i;
		mp[se[i]] = i;
	}
	int turn;
	cin >> turn;
	if (turn == 1) {
		int ptr = 0;
		for (int i = 0; i < n; i++) {
			if (ptr < m) {
				if (power[fi[ptr]] < power[se[ptr]])
					swap(fi[ptr], se[ptr]);
				cout << fi[ptr] + 1 << endl;
				s.erase(MP(-power[fi[ptr]], fi[ptr]));
				int tmp;
				cin >> tmp, tmp--;
				s.erase(MP(-power[tmp], tmp));
				ptr++;
			}
			else {
				int id = s.begin()->R;
				cout << id + 1 << endl;
				s.erase(s.begin());
				int tmp;
				cin >> tmp, tmp--;
				s.erase(MP(-power[tmp], tmp));
			}
		}
	}
	else {
		int ptr = 0;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp, tmp--;
			s.erase(MP(-power[tmp], tmp));
			if (mp[tmp] != -1) {
				int qid = mp[tmp];
				int id = fi[qid] ^ se[qid] ^ tmp;
				if (s.find(MP(-power[id], id)) != s.end()) {
					cout << id + 1 << endl;
					s.erase(MP(-power[id], id));
					continue;
				}
			}
			while (ptr < m and s.find(MP(-power[fi[ptr]], fi[ptr])) == s.end())
				ptr++;
			if (ptr < m) {
				if (power[fi[ptr]] < power[se[ptr]])
					swap(fi[ptr], se[ptr]);
				cout << fi[ptr] + 1 << endl;
				s.erase(MP(-power[fi[ptr]], fi[ptr]));
				ptr++;
			}
			else {
				int id = s.begin()->R;
				cout << id + 1 << endl;
				s.erase(s.begin());
			}
		}
	}
	return 0;
}