#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	
    for (int i=1; i<s.size(); ++i) {
        if (s[i] == s[i-1]) {
            if (s[i] != 'a' && s[i+1] != 'a') s[i] = 'a';
            else if (s[i] != 'b' && s[i+1] != 'b') s[i] = 'b';
            else s[i] = 'c';
        }
    }

    for (int i=0; i<s.size(); ++i) cout << s[i];
    cout << '\n';	
	return 0;
}