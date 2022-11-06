#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;

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
        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[x]++;
        }
        vector<int> vec;
        int sum = 0;
        for (auto it : freq)
        {
            sum += it.second;
            vec.push_back(it.second);
        }
        sort(vec.begin(), vec.end());
        int ans = n;
        int temp = 0;
        int prev = 0;
        for (int i = 0; i < (int) vec.size(); i++)
        {
            int diff = vec[i] - prev;
            int cnt = (int) vec.size() - i;
            sum -= diff * cnt;
            ans = min(ans, temp + sum);
            prev = vec[i];
            temp += vec[i];
        }
        cout << ans << "\n";
    }
    return 0;
}