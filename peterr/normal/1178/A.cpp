#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
pair<int, int> parties[MAXN + 1];

int main()
{
    int n, total = 0;;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> parties[i].first;
        parties[i].second = i;
        total += parties[i].first;
    }
    sort(parties + 2, parties + n + 1);
    if (parties[1].first * 2 > total)
    {
        cout << 1 << endl;
        cout << 1 << endl;
    }
    else
    {
        int index = 2;
        vector<int> vec;
        vec.push_back(1);
        int votes = parties[1].first;
        while (index <= n && parties[1].first >= parties[index].first * 2)
        {
            votes += parties[index].first;
            vec.push_back(parties[index].second);
            index++;
        }
        if (votes * 2 > total)
        {
            cout << vec.size() << endl;
            for (int i : vec)
                cout << i << " ";
            cout << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}