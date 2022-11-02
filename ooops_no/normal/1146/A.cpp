#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.length(), a = count(s.begin(), s.end(), 'a');
    if (a < n){
        while(a * 2 <= n){
            n--;
        }
    }
    cout << n;
}