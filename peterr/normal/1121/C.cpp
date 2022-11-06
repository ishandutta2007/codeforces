#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MAXK = 100;
int submissions[MAXN];
bool interesting[MAXN];
pair<int, int> testing[MAXK];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> submissions[i];
    }
    for (int i = 0; i < k; i++)
    {
        testing[i] = {i, 1};
    }
    int curSub = k;
    int completed = 0;
    while (completed < n)
    {
        int percent = (int) round(100 * ((long double) completed / n));
        for (int i = 0; i < k; i++)
        {
            if (testing[i].first >= n)
                continue;
            if (testing[i].second == percent)
            {
                interesting[testing[i].first] = true;
            }
            if (testing[i].second == submissions[testing[i].first])
            {
                testing[i] = {curSub, 1};
                curSub++;
                completed++;
            }
            else
            {
                testing[i].second++;
            }
        }
    }
    cout << count(interesting, interesting + n, true) << endl;
    return 0;
}