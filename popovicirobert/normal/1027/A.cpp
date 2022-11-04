#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, t, i;
    ios::sync_with_stdio(false);
    cin >> t;
    while(t > 0) {
        t--;
        string str;
        cin >> n;
        cin >> str;
        bool flag = 1;
        for(i = 0; i < n - i - 1; i++) {
            int a = n - i - 1;
            if(str[i] == str[a] || max(str[i], str[a]) - min(str[i], str[a]) == 2)
                continue;
            flag = 0;
        }
        if(flag) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}