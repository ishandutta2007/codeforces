#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<string> q;

int main(){
    ios::sync_with_stdio(0);
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++){
        int a = 0, b = 0;
        string now;
        for (int j = i; j < n; j++){
            if (s[j] == 'L')
                a--;
            if (s[j] == 'R')
                a++;
            if (s[j] == 'U')
                b++;
            if (s[j] == 'D')
                b--;
            if (a == 0 && b == 0)
                ans++;
        }
    }
    cout << ans;
}