#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ro = 0, re = 0;
        int bo = 0, be = 0;
        int oo = 0;
        for (int i = 0; i < n; i++) {
            bool odd_place = i%2 == 0;
            bool odd_digit = s[i]%2 == 1;
            if (odd_place) {
                if (odd_digit) {ro++; oo++;}
                else re++;
            } else {
                if (odd_digit) {bo++; oo++;}
                else be++;
            }
        }
        for (int i = 0; i < n-1; i++) {
            if (i%2 == 0) {
                if (re) re--;
                else {ro--; oo--;}
            } else {
                if (bo) {bo--; oo--;}
                else be--;
            }
        }
        if (oo) cout << "1\n";
        else cout << "2\n";
    }
}