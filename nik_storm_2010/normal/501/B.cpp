#include <iostream>

using namespace std;
const int N = 2e3;

string from[N], to[N];

int main() {
    ios_base::sync_with_stdio(false);
    int n{}, cnt{};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s1{}, s2{};
        cin >> s1 >> s2;
        int num{};
        for (int j = 1; j <= cnt; j++)
            if (to[j] == s1)
                num = j;
        if (num)
            to[num] = s2;
        else {
            cnt++;
            from[cnt] = s1;
            to[cnt] = s2;
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++)
        cout << from[i] << " " << to[i] << "\n";
    return 0;
}