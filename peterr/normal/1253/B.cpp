#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ptr = 0;
    vector<int> ans;
    bool valid = true;
    while (valid && ptr < n)
    {
        int start = ptr;
        if (a[ptr] < 0)
        {
            valid = false;
            break;
        }
        unordered_set<int> seen;
        unordered_set<int> office;
        seen.insert(a[ptr]);
        office.insert(a[ptr]);
        int bal = 1;
        ptr++;
        while (ptr < n && bal > 0)
        {
            int p = a[ptr];
            if (p > 0)
            {
                if (seen.find(p) != seen.end())
                {
                    valid = false;
                    break;
                }
                office.insert(p);
                seen.insert(p);
                bal++;
            }
            else
            {
                if (office.find(-p) == office.end())
                {
                    valid = false;
                    break;
                }
                office.erase(-p);
                bal--;
            }
            ptr++;
        }

        if (bal != 0)
        {
            valid = false;
            break;
        }
        ans.push_back(ptr - start);
    }
    if (!valid)
        cout << -1 << endl;
    else
    {
        cout << (int) ans.size() << endl;
        for (int i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}