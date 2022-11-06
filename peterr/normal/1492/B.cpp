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
        cin >> n;
        vector<int> vec(n);
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(i + 1);
            cin >> vec[i];
        }
        vector<int> ans;
        vector<int> temp;
        int big = n;
        int ptr = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            s.erase(vec[i]);
            if (vec[i] == big)
            {
                for (int j = i; j <= ptr; j++)
                {
                    ans.push_back(vec[j]);
                }
                if (i)
                {
                    big = *(--s.end());
                }
                ptr = i - 1;
            }
        }
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}