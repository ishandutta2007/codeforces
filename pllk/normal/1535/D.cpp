#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s;

int c[1<<20];

void update(int k) {
    while (k >= 1) {
        if (k >= (1<<(n-1))) {
            c[k] = s[k] == '?' ? 2 : 1;
        } else if (s[k] == '1') {
            c[k] = c[2*k];
        } else if (s[k] == '0') {
            c[k] = c[2*k+1];
        } else {
            c[k] = c[2*k]+c[2*k+1];
        }
        k /= 2;
    }
}

int main() {
    cin >> n;
    cin >> s;
    reverse(s.begin(),s.end());
    s = "?"+s;
    for (int i = (1<<n)-1; i >= 1; i--) {
        c[i] = 1;
        update(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        k = (1<<n)-k;
        char x;
        cin >> x;
        s[k] = x;
        update(k);
        cout << c[1] << "\n";
    }
}