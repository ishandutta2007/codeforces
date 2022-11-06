#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int ht[MAXN];

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int h, n;
        cin >> h >> n;
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            cin >> ht[i];
            vec.push_back(ht[i]);
        }
        int ans = 0;
        sort(vec.begin(), vec.end());
        while (vec.size() > 1)
        {
            int s = vec.size();
            int pos = vec[s - 1];
            int nextPos = vec[s - 2];
            if (pos <= 2)
                break;
            if (pos >= nextPos + 2)
            {
                vec.pop_back();
                vec.push_back(nextPos + 1);
            }
            else
            {
                if (vec.size() == 2 || vec[s - 3] != nextPos - 1)
                {
                    ans++;
                    vec.pop_back();
                    vec.pop_back();
                    vec.push_back(nextPos - 1);
                }
                else
                {
                    vec.pop_back();
                    vec.pop_back();
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}