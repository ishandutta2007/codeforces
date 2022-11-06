#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int ans = 0;
        int ptr = 0;
        vector<int> v;
        while (ptr < (int) s.length())
        {
            int cnt = 0;
            char ch = s[ptr];
            while (ptr < (int) s.length() && s[ptr] == ch)
            {
                ptr++;
                cnt++;
            }
            v.push_back(cnt);
        }
        ptr = 0;
        int ptr2 = 0;
        while (ptr < (int) v.size())
        {
            ans++;
            ptr2 = max(ptr2, ptr);
            while (ptr2 < (int) v.size() && v[ptr2] == 1)
            {
                ptr2++;
            }
            if (ptr2 < (int) v.size())
            {
                v[ptr2]--;
            }
            else
            {
                ptr++;
            }
            ptr++;
        }
        cout << ans << "\n";
    }
    return 0;
}