#include <iostream>
#include <set>

using namespace std;

int n;
int u;

set<string> s;

void lol(string a, string b, int c) {
    u = max(u,c);
    for (int i = 1; i < n; i++) {
        int z = 0;
        if (a[i-1] == '0') z++;
        if (b[i-1] == '0') z++;
        if (a[i] == '0') z++;
        if (b[i] == '0') z++;
        if (z < 3) {a[i-1] = 'X';b[i-1]='X';}
        else break;
    }
    if (s.count(a+b)) return;
    s.insert(a+b);
    int f = -1;
    for (int i = 0; i < n-1; i++) {
        if (f != -1 && f < i-1) break;
        if (a[i] == '0' && a[i+1] == '0' && b[i] == '0') {
            a[i] = a[i+1] = b[i] = 'X';
            lol(a,b,c+1);
            if (f == -1) f = i;
        }
        if (a[i] == '0' && a[i+1] == '0' && b[i+1] == '0') {
            a[i] = a[i+1] = b[i+1] = 'X';
            lol(a,b,c+1);
            if (f == -1) f = i;
        }
        if (a[i] == '0' && b[i] == '0' && b[i+1] == '0') {
            a[i] = b[i] = b[i+1] = 'X';
            lol(a,b,c+1);
            if (f == -1) f = i;
        }
        if (a[i+1] == '0' && b[i] == '0' && b[i+1] == '0') {
            a[i+1] = b[i] = b[i+1] = 'X';
            lol(a,b,c+1);
            if (f == -1) f = i;
        }
    }
}

int main() {
    string a, b;
    cin >> a >> b;
    n = a.size();
    lol(a,b,0);
    cout << u << "\n";
}