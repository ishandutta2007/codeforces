#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.length();
    if (n % 2 != 0) {
        for (int i = 0; i < (n+1)/2; i++) cout << '4';
        for (int i = 0; i < (n+1)/2; i++) cout << '7';
    }
    else {
        string ans;
        for (int i = 0; i < n/2; i++) ans.push_back('7');
        for (int j = 0; j < n/2; j++) ans.push_back('4');
        string temp = ans;

        do {
            if (temp >= s)
                ans = min(ans, temp);
        } while (prev_permutation(temp.begin(), temp.end()));

        if (ans < s) {
            for (int i = 0; i <= n/2; i++) cout << '4';
            for (int i = 0; i <= n/2; i++) cout << '7';
        }
        else cout << ans;
    }
    cout << "\n";
    return 0;
}