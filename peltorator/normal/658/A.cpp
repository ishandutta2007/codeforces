#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector<int> p(n), t(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> t[i];
    long long s1 = 0;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        time += t[i];
        s1 += max(0, p[i] - time * c);
    }
    time = 0;
    long long s2 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        time += t[i];
        s2 += max(0, p[i] - time * c);
    }
    if (s1 > s2)
        cout << "Limak";
    else if (s1 < s2)
        cout << "Radewoosh";
    else
        cout << "Tie";
    return 0;
}