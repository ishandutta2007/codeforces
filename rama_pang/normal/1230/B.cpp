#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lint = long long;

int main() {
    int N, K; cin >> N >> K;
    string s; cin >> s;
    if (K == 0) {
        cout << s << "\n";
    } else if (s.size() == 1) {
        cout << "0\n";
    } else {
        K-= (s[0] != '1');
        s[0] = '1';
        int loc = 1;
        while (loc < s.size() && K > 0) {
            if (s[loc] != '0') K--;
            s[loc] = '0';
            loc++;
        }
        cout << s << "\n";
        
    }
}