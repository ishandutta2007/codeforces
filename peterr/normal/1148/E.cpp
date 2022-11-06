#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
pair<int, int> s[MAXN];
int t[MAXN];
vector<tuple<int, int, int>> neg;
vector<tuple<int, int, int>> pos;

int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].first;
        s[i].second = i + 1;
        sum += s[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        sum -= t[i];
    }
    sort(s, s + n);
    sort(t, t + n);
    bool ans = sum == 0;
    for (int i = 0; i < n; i++)
    {
        tuple<int, int, int> tup = make_tuple(s[i].first, t[i] - s[i].first, s[i].second);
        if (get<1>(tup) > 0)
            pos.push_back(tup);
        else if (get<1>(tup) < 0)
            neg.push_back(tup);
    }
    vector<tuple<int, int, int>> vec;
    int p1, p2;
    p1 = p2 = 0;
    while (p1 < (int) pos.size() && p2 < (int) neg.size())
    {
        tuple<int, int, int> t1 = pos[p1];
        tuple<int, int, int> t2 = neg[p2];
        if (get<0>(t1) >= get<0>(t2))
        {
            ans = false;
            break;
        }
        int d = min(get<1>(t1), -get<1>(t2));
        vec.push_back(make_tuple(get<2>(t1), get<2>(t2), d));
        get<0>(t1) += d;
        get<1>(t1) -= d;
        pos[p1] = t1;
        get<0>(t2) -= d;
        get<1>(t2) += d;
        neg[p2] = t2;
        if (get<1>(t1) == 0)
            p1++;
        if (get<1>(t2) == 0)
            p2++;
    }
    if (p1 < (int) pos.size() || p2 < (int) neg.size())
        ans = false;
    if (ans)
    {
        cout << "YES\n";
        cout << vec.size() << "\n";
        for (tuple<int, int, int> tup : vec)
            cout << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup) << "\n";
    }
    else
        cout << "NO\n";
    return 0;
}