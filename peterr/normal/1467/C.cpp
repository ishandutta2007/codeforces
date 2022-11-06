#include <bits/stdc++.h>

using namespace std;

long long solve(vector<int> &a, vector<int> &b, vector<int> &c)
{
    long long ans = 0;
    for (int x : a)
        ans += x;
    for (int x : b)
        ans += x;
    for (int x : c)
        ans -= x;
    long long temp = 0;
    for (int x : a)
        temp += x;
    for (int x : b)
        temp += x;
    for (int x : c)
        temp += x;
    temp -= 2 * c[0];
    temp -= 2 * b[0];
    ans = max(ans, temp);
    return ans;
}

void readInput(vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
        cin >> v[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> a(n1);
    vector<int> b(n2);
    vector<int> c(n3);
    readInput(a, n1);
    readInput(b, n2);
    readInput(c, n3);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    long long ans = solve(a, b, c);
    ans = max(ans, solve(a, c, b));
    ans = max(ans, solve(b, a, c));
    ans = max(ans, solve(b, c, a));
    ans = max(ans, solve(c, a, b));
    ans = max(ans, solve(c, b, a));
    cout << ans << "\n";
    return 0;
}