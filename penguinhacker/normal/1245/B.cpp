#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void doStuff(int n, int a, int b, int c, int d, int e, int f, string s) {
	int surplusR, surplusP, surplusS;
	surplusR = surplusP = surplusS = 0;
	if (a>f) surplusR = a-f;
	if (b>d) surplusP = b-d;
	if (c>e) surplusS = c-e;

	for (int i=0; i<n; ++i) {
		if (s[i] == 'R') {
			if (b>0) {
				cout << 'P';
				b--;
			}
			else {
				if (surplusR>0) {
					cout << 'R';
					surplusR--;
				}
				else if (surplusS>0) {
					cout << 'S';
					surplusS--;
				}
			}
		}
		else if (s[i] == 'P') {
			if (c>0) {
				cout << 'S';
				c--;
			}
			else {
				if (surplusR>0) {
					cout << 'R';
					surplusR--;
				}
				else if (surplusP>0) {
					cout << 'P';
					surplusP--;
				}
			}
		}
		else {
			if (a>0) {
				cout << 'R';
				a--;
			}
			else {
				if (surplusP>0) {
					cout << 'P';
					surplusP--;
				}
				else if (surplusS>0) {
					cout << 'S';
					surplusS--;
				}
			}
		}
	}
	cout << '\n';
}

int main() {
	int t;
	cin >> t;
    while (t--) {
		int n, a, b, c;
		string s;
		cin >> n >> a >> b >> c >> s;
		int rock, paper, sciss; //for Bill
		rock = paper = sciss = 0;
		for (int i=0; i<n; ++i) {
			if (s[i] == 'R') rock++;
			else if (s[i] == 'P') paper++;
			else sciss++;
		}

		int won = min(a, sciss) + min(b, rock) + min(c, paper);
		if (won >= (n+1)/2) {
			cout << "YES\n";
			doStuff(n, a, b, c, rock, paper, sciss, s);
		}
		else cout << "NO\n";
    }
	return 0;
}