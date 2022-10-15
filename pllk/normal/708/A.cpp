#include <iostream>

using namespace std;

bool ok;
string s;
int n;

int main() {
    cin >> s;
    n = s.size();
    if (s[0] != 'a') {
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') break;
            s[i]--;
            ok = true;
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (s[i] != 'a') {
                for (int j = i; j < n; j++) {
                    if (s[j] == 'a') break;
                    s[j]--;
                    ok = true;
                }
                break;
            }
        }
    }
    if (!ok) s[n-1] = 'z';
    cout << s << "\n";
}