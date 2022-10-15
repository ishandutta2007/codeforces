#include <iostream>

using namespace std;

typedef long long ll;

int n;
string s[111];
ll c;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = "*"+s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= n; a++) {
            for (int b = a+1; b <= n; b++) {
                if (s[i][a] == 'C' && s[i][b] == 'C') c++;
                if (s[a][i] == 'C' && s[b][i] == 'C') c++;
            }
        }
    }
    cout << c << "\n";
}