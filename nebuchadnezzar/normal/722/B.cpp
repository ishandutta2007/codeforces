#include <bits/stdc++.h>
#define ff first
#define ss second
#define puba push_back
#define szof(x) ((int) (x).size())
#define bend(x) (x).begin(), (x).end()

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n;
char s[1000];

int main() {
	scanf("%d", &n);

	vector<int> inp;
	for (int i = 0; i < n; ++i) {
	 	int num;
	 	scanf("%d", &num);
	 	inp.puba(num);
	}


	gets(s);

	for (int i = 0; i < n; ++i) {
	 	gets(s);
	 	int l = strlen(s);
	 	int num = 0;
	 	for (int j = 0; j < l; ++j) {
	 	 	if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y') {
	 	 	 	++num;
	 	 	}
	 	}
	 	if (num != inp[i]) {
	 	 	cout << "NO\n";
	 	 	return 0;
	 	}
	}

	cout << "YES\n";

	#ifdef LOCAL
		cerr << "time: " << clock() << endl;
	#endif
	return 0;
}