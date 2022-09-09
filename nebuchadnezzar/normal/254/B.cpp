#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, mou[12], d, m, p, t, date, type, person;
vector <pair <int, pair <int, int> > > mas;
pair <int, pair <int, int> > inf;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    mou[0] = 31; mou[1] = 28; mou[2] = 31; mou[3] = 30; mou[4] = 31; mou[5] = 30; mou[6] = 31; mou[7] = 31; mou[8] = 30; mou[9] = 31; mou[10] = 30; mou[11] = 31;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> m >> d >> p >> t;
        int dm = 0;
        for (int j = 0; j < m - 1; ++j)
        {
            dm += mou[j];
        }
        mas.push_back(make_pair(dm + d - t, make_pair(0, p)));
        mas.push_back(make_pair(dm + d - 1, make_pair(1, p)));
    }
    sort(mas.begin(), mas.end());

    int ans = 0;
    int bal = 0;
    for (int i = 0; i < mas.size(); ++i)
    {
        inf = mas[i];
        date = inf.first;
        type = inf.second.first;
        person = inf.second.second;
        if(type == 0)
        {
            //cout << person << endl;
            bal += person;
            if(bal > ans)
                ans = bal;

        }
        else
        {
            bal -= person;
        }
    }
    cout << ans;
    return 0;
}