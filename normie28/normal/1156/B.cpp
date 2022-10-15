#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long
ll a, b, n, m, i, j;

bool isUgly(string &S)
{
    for (int i = 1; i < S.length(); i++)
    {
        if (abs(S[i] - S[i - 1]) == 1)
            return true;
    }
    return false;
}

void check_and_insert(string &new_S, char c)
{
    int n = new_S.length();
    if (n == 0)
    {
        new_S += c;
        return;
    }
    for (int i = n - 1; i > 0; i--)
    {

        if ((abs(new_S[i] - new_S[i - 1]) == 1) && (abs(new_S[i] - c) != 1 && abs(new_S[i - 1] - c) != 1))
        {
            new_S.insert(new_S.begin() + i, c);
            return;
        }
    }
    if (abs(new_S[n - 1] - c) != 1)
    {
        new_S += c;
        return;
    }
    if (abs(new_S[0] - c) != 1)
    {
        new_S = c + new_S;
        return;
    }
    new_S += c;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        sort(S.begin(), S.end());
        ll n = S.length();
        string new_S = "";
        for (int i = 0; i < n; i++)
        {
            check_and_insert(new_S, S[i]);
        }
        // cout << new_S << endl;
        if (isUgly(new_S))
            cout << "No answer" << endl;
        else
            cout << new_S << endl;
    }
}