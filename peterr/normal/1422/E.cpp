#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5 + 1;
const int MAXK = 11;
int len[MAXN];
bool par[MAXN];
string pref[MAXN];
string suf[MAXN];
bool fll[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    s += 'A';
    int n = (int) s.length();
    len[n - 1] = 1;
    par[n - 1] = 1;
    pref[n - 1] = suf[n - 1] = "A";
    int mn = s[n - 1];
    int nxt = n - 1;
    int streak = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] != s[i + 1])
        {
            streak = 1;
            nxt = i + 1;
            if (par[i + 1] == 1)
            {
                mn = s[i + 1];
            }
            else
            {
                mn = min(mn, (int) s[i + 1]);
            }
            par[i] = 1;
        }
        else
        {
            streak++;
            par[i] = !par[i + 1];
        }
        if (par[i] == 1)
        {
            if (s[i] < pref[nxt][0] || (s[i] == pref[nxt][0] && fll[nxt]))
            {
                len[i] = streak + len[nxt];
                pref[i] = s.substr(i, min(streak, MAXK)) + pref[nxt].substr(0, max(0, MAXK - streak));
                suf[i] = suf[nxt];
                if ((int) suf[i].length() < 3)
                {
                    suf[i] = s.substr(i, min(streak, 3 - (int) suf[i].length())) + suf[i];
                }
                fll[i] = true;
            }
            else
            {
                len[i] = 1 + len[nxt];
                pref[i] = s[i] + pref[nxt].substr(0, MAXK - 1);
                suf[i] = suf[nxt];
                if ((int) suf[i].length() < 3)
                {
                    suf[i] = s[i] + suf[i];
                }
                fll[i] = false;
            }
        }
        else
        {
            if (s[i] > mn || (s[i] == mn && !fll[nxt]))
            {
                len[i] = len[nxt];
                pref[i] = pref[nxt];
                fll[i] = fll[nxt];
                suf[i] = suf[nxt];
            }
            else
            {
                len[i] = streak + len[nxt];
                pref[i] = s.substr(i, min(streak, MAXK)) + pref[nxt].substr(0, max(0, MAXK - streak));
                suf[i] = suf[nxt];
                if ((int) suf[i].length() < 3)
                {
                    suf[i] = s.substr(i, min(streak, 3 - (int) suf[i].length())) + suf[i];
                }
                fll[i] = true;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << len[i] - 1 << " ";
        if (len[i] <= 11)
        {
            cout << pref[i].substr(0, (int) pref[i].length() - 1) << "\n";
        }
        else
        {
            cout << pref[i].substr(0, 5) << "...";
            cout << suf[i].substr(0, 2);
            cout << "\n";
        }
        //cout << suf[i] << endl;
    }
    return 0;
}