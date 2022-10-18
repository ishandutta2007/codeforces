#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'A')
            k++;
    if (k * 2 > n)
        cout << "Anton";
    else if (k * 2 == n)
        cout << "Friendship";
    else
        cout << "Danik";
    return 0;
}