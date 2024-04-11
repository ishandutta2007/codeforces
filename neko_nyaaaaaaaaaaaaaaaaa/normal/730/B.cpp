#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int t; char c;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> winner;
		vector<int> loser;
		if (n % 2) {
		      winner.push_back(n);
		      loser.push_back(n);
		}
		for (int i = 1; i < n; i += 2) {
		      cout << "? " << i << " " << i+1 << endl;
		      cin >> c;
		      if (c == '>') {
		            winner.push_back(i);
		            loser.push_back(i+1);
		      } else {
		            loser.push_back(i);
		            winner.push_back(i+1);
		      }
		}
		int min = 0, max = 0;
		for (int i = 1; i < loser.size(); i++) {
		      cout << "? " << loser[min] << " " << loser[i] << endl;
		      cin >> c;
		      if (c == '>') {
		            min = i;
		      }
		}
		for (int i = 1; i < winner.size(); i++) {
		      cout << "? " << winner[max] << " " << winner[i] << endl;
		      cin >> c;
		      if (c == '<') {
		            max = i;
		      }
		}
		cout << "! " << loser[min] << " " << winner[max] << endl;
	}
	
	return 0;
}