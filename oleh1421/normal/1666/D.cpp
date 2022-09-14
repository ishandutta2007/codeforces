#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--)
    {
        string s, t;
        cin >> s >> t;
        set<char> letters(t.begin(), t.end());
        string ns = "";
        for (char i : s) if (letters.find(i) != letters.end()) ns += i;
        s = ns;
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        string res = "";
        for (int i = 0, ind = 0; ind < s.size(); ++ind)
        {
            bool isthe = false;
            for (int j = i + 1; j < t.size(); ++j) isthe = isthe || (t[j] == s[ind]);
            if (isthe && s[ind] != t[i]) break;
            else if (s[ind] == t[i])
            {
                res += t[i];
                ++i;
            }
        }
        if (res != t) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}