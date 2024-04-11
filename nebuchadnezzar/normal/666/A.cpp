#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e4 + 5;

char s[MAXN];
set<string> ans;
set<pair<int, string>> was;

int rec(int pos, string q) {
	if (was.count({pos, q})) {
	 	return 0;
	}
	was.insert({pos, q});
 	if (pos <= 4) {
 	 	return 0;
 	}
 	if (pos - 2 >= 4) {
 		string tmp = "";
 		tmp += s[pos - 1];
 		tmp += s[pos];
 		if (tmp != q) {
     	 	ans.insert(tmp);
     	 	rec(pos - 2, tmp);
 	 	}
 	}
 	if (pos - 3 >= 4) {
 		string tmp = "";
 		tmp += s[pos - 2];
 		tmp += s[pos - 1];
 		tmp += s[pos];
 		if (tmp != q) {
    	 	ans.insert(tmp);
    	 	rec(pos - 3, tmp);
 	 	}
 	}
 	return 0;
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%s", s);

	int n = strlen(s);

	rec(n - 1, "");

	cout << szof(ans) << "\n";
	for (auto w: ans) {
	 	cout << w << "\n";
	}

	return 0;
}