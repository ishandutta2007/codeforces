#include <iostream>

using namespace std;

int nn;
string a, b;
int n[2][2];
int t1, t2;

int main() {
    cin >> nn >> a >> b;
    for (int i = 0; i < 2*nn; i++) {
        n[a[i]-'0'][b[i]-'0']++;
    }
    for (int i = 0; i < nn; i++) {
        if (n[1][1] > 0) {
            n[1][1]--;
            t1++;
        } else if (n[1][0] > 0) {
            n[1][0]--;
            t1++;
        } else if (n[0][1] > 0) {
            n[0][1]--;
        } else {
            n[0][0]--;
        }
        if (n[1][1] > 0) {
            n[1][1]--;
            t2++;
        } else if (n[0][1] > 0) {
            n[0][1]--;
            t2++;
        } else if (n[1][0] > 0) {
            n[1][0]--;
        } else {
            n[0][0]--;
        }
    }
    if (t1 == t2) {
        cout << "Draw\n";
    } else if (t1 > t2) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}