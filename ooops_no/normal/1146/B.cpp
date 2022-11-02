#include <bits/stdc++.h>

using namespace std;

#define pb push_back

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    string s1 = "" , s2 = "";
    int m = 0, k = 0, f = s.length();
    for (auto to : s){
        if (to != 'a'){
            s2 += to;
            k++;
        }
        s1 += to;
        m++;
        if (m + k == f && s1 + s2 == s){
            cout << s1;
            return 0;
        }
    }
    cout << ":(";
}