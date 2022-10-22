#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s;
    cin >> s;
	int n = s.size();
    vector<int> O, C; //open and closed
    for (int i=0; i<n; ++i) {
        if (s[i] == '(') {
            O.push_back(i);
        }
        else C.push_back(i);
    }
    reverse(C.begin(), C.end());

    int remove = 0;
    for (int i=0; i<min(O.size(), C.size()); ++i) {
        if (O[i] < C[i]) remove++;
        else break;
    }

    if (remove == 0) {
        cout << 0 << '\n';
        return 0;
    }

    cout << 1 << '\n' << 2*remove << '\n';
    vector<int> toRemove;
    for (int i=0; i<remove; ++i) {
        toRemove.push_back(O[i]+1);
        toRemove.push_back(C[i]+1);
    }
    sort(toRemove.begin(), toRemove.end());

    for (int i : toRemove) cout << i << ' ';
	return 0;
}