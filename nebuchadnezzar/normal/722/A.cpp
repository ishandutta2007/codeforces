#include <bits/stdc++.h>
#define ff first
#define ss second
#define puba push_back
#define szof(x) ((int) (x).size())
#define bend(x) (x).begin(), (x).end()

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

char s[10];

int main() {
	int h;
	scanf("%d", &h);
	scanf("%s", s);

	if (s[3] > '5') {
   	 	s[3] = '5';
   	}
   	

	if (h == 24) {
	 	if (s[0] > '2') {
	 	 	s[0] = '0';
	 	} else if (s[0] == '2') {
	 	 	if (s[1] > '3') {
	 	 	 	s[1] = '0';
	 	 	}
	 	}
	} else {
	 	if (s[0] > '1') {
	 		if (s[1] == '0') {
	 		 	s[0] = '1';
	 		} else {
	 	 		s[0] = '0';
	 	 	}
	 	} else if (s[0] == '1') {
	 	 	if (s[1] > '2') {
	 	 	 	s[1] = '0';
	 	 	}
	 	} else if (s[0] == '0' && s[1] == '0') {
	 	 	s[1] = '1';
	 	}
	}

	cout << s << "\n";
	

	#ifdef LOCAL
		cerr << "time: " << clock() << endl;
	#endif
	return 0;
}