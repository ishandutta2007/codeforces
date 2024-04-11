#include "iostream"
#include "vector"
#include "queue"
#include "deque"
#include "string"
#include "list"
#include "unordered_map"
#include "unordered_set"

using namespace std;

const long long int MOD = 1000000007;

int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	unordered_map<string, pair<int, string>>m;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		unordered_set<string>us;
		for (int j = 0; j < s.size(); j++) {
			string t;
			for (int k = j; k < s.size(); k++) {
				t.push_back(s[k]);
				us.insert(t);
			}
		}
		for (auto j : us) {
			if (m.find(j) == m.end()) {
				m[j].first++;
				m[j].second = s;
			}
			else {
				m[j].first++;
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (m.find(s) == m.end()) {
			cout << 0 <<" -"<< endl;
		}
		else {
			cout << m[s].first << " " << m[s].second << endl;
		}
	}
	return 0;
}