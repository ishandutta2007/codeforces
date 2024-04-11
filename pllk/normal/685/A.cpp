#include <iostream>

using namespace std;

typedef long long ll;

string lol(int x) {
    if (x == 0) return "0";
    string u = "";
    while (x > 0) {
        u = to_string(x%7)+u;
        x /= 7;
    }
    return u;
}

string s;

ll d[100][2][1<<10];
ll t;

bool ok(int b, int x) {
    return !(b&(1<<x));
}

int main() {
    int a, b;
    cin >> a >> b;
    s = lol(a-1) + ":" + lol(b-1);
    int n = s.size();
    d[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int b = 0; b < (1<<10); b++) {
            if (s[i] == ':') {
                d[i+1][0][b] += d[i][0][b];
                d[i+1][0][b] += d[i][1][b];
            } else {
                if (ok(b,s[i]-'0')) d[i+1][0][b|(1<<(s[i]-'0'))] += d[i][0][b];
                for (int k = 0; k < s[i]-'0'; k++) {
                    if (ok(b,k)) d[i+1][1][b|(1<<k)] += d[i][0][b];
                }
                for (int k = 0; k < 7; k++) {
                    if (ok(b,k)) d[i+1][1][b|(1<<k)] += d[i][1][b];
                }
            }
        }
    }
    for (int b = 0; b < (1<<10); b++) {
        t += d[n][0][b];
        t += d[n][1][b];
    }
    cout << t << "\n";
}