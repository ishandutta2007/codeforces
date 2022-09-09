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

char s[4][3];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	for (int i = 0; i < 4; ++i) {
	 	scanf("%s", s[i]);
	}

	if (s[0][0] == 'X') {
	 	s[0][0] = s[0][1];
	 	s[0][1] = s[1][1];
	 	s[1][1] = 'X';
	} else if (s[0][1] == 'X') {
	 	swap(s[0][1], s[1][1]);
	} else if (s[1][0] == 'X') {
	 	swap(s[1][0], s[1][1]);
	}


	if (s[2][0] == 'X') {
	 	s[2][0] = s[2][1];
	 	s[2][1] = s[3][1];
	 	s[3][1] = 'X';
	} else if (s[2][1] == 'X') {
	 	swap(s[2][1], s[3][1]);
	} else if (s[3][0] == 'X') {
	 	swap(s[3][0], s[3][1]);
	}

	vector<char> s1;
	s1.puba(s[0][0]);
	s1.puba(s[0][1]);
	s1.puba(s[1][0]);

	vector<char> s2;
	s2.puba(s[2][0]);
	s2.puba(s[2][1]);
	s2.puba(s[3][0]);

    for (int i = 0; i < 3; ++i) {
     	if (s1 == s2) {
     	 	cout << "YES\n";
     	 	return 0;
     	}
     	rotate(s1.begin(), s1.begin() + 1, s1.end());
    }

	cout << "NO\n";

	return 0;
}