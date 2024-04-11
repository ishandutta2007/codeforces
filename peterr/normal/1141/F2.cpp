#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1500;
int arr[MAXN + 1];
unordered_map<int, vector<pair<int, int>>> ranges;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = i; j >= 1; j--)
        {
            sum += arr[j];
            if (ranges.find(sum) == ranges.end())
            {
                ranges[sum].push_back({j, i});
            }
            else
            {
                if (j > ranges[sum].back().second)
                {
                    ranges[sum].push_back({j, i});
                }
            }
        }
    }
    int bestSum = 0;
    int blocks = 0;
    for (auto it = ranges.begin(); it != ranges.end(); it++)
    {
        if ((int) it->second.size() > blocks)
        {
            blocks = (int) it->second.size();
            bestSum = it->first;
        }
    }
    cout << blocks << endl;
    for (pair<int, int> p : ranges[bestSum])
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}