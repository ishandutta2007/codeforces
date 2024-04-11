#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int k; cin >> k;
    string s; cin >> s;
    std::vector<std::vector<int> > win(n + 1, std::vector<int> (2 * k + 1, 0));
    win[0][k] = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'D') {
            win[i] = win[i - 1];
        } else if(s[i - 1] == 'W') {
            for (int j = 2 * k; j >= 1; --j)
                win[i][j] = win[i - 1][j - 1]; 
            win[i][0] = 0;
        } else if(s[i - 1] == 'L') {
            for (int j = 0; j < 2 * k; ++j)
                win[i][j] = win[i - 1][j + 1]; 
            win[i][2 * k] = 0;
        } else {
            for (int j = 1; j < 2 * k; ++j)
                win[i][j] = win[i - 1][j + 1] | win[i - 1][j - 1] | win[i - 1][j];
            win[i][0] = win[i - 1][0] | win[i - 1][1];
            win[i][2 * k] = win[i - 1][2 * k] | win[i - 1][2 * k - 1];
        }
        if (i != n) {
            win[i][0] = 0;
            win[i][2 * k] = 0;
        } 
    }
    if (win[n][0] | win[n][2 * k]) {
        string s1 = "";
        string p = "a";
        int state = (win[n][0] ? 0 : 2 * k);
        for (int i = n; i >= 1; --i) {
            if (s[i - 1] == 'W') {
                state = state - 1;
                p[0] = s[i - 1];
                s1 += p;
            } else if(s[i - 1] == 'L') {
                state = state + 1;    
                p[0] = s[i - 1];
                s1 += p;
            } else if(s[i - 1] == 'D') {    
                p[0] = s[i - 1];
                s1 += p;
            } else {
                if (state != 0 && win[i - 1][state - 1]) {
                    state = state - 1;
                    p[0] = 'W';
                    s1 += p;
                } else if(state != 2 * k && win[i - 1][state + 1]) {
                    state = state + 1;
                    p[0] = 'L';
                    s1 += p;
                } else {
                    p[0] = 'D';
                    s1 += p;
                }
            }
        }
        reverse(s1.begin(), s1.end());
        cout << s1;
    } else {
        cout << "NO";
    }
}