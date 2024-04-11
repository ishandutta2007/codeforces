#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    pair<int, int>* a = new pair<int, int>[n+1];
    pair<int, int>* b = new pair<int, int>[n+1];
    for (int i = 1; i <= n; i++)
    {
        int first, second;
        cin >> first >> second;
        a[i] = {first, i};
        b[i] = {second, i};
    }

    vector<pair<int, int>> inc;
    vector<pair<int, int>> dec;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].first < b[i].first)
        {
            inc.push_back({b[i].first, i});
        }
        else
        {
            dec.push_back({b[i].first, i});
        }
    }

    sort(inc.rbegin(), inc.rend());
    sort(dec.begin(), dec.end());

    if (inc.size() > dec.size())
    {
        cout << inc.size() << endl;
        for (int i = 0; i < inc.size(); i++)
            cout << inc[i].second << " ";
    }
    else
    {
        cout << dec.size() << endl;
        for (int i = 0; i < dec.size(); i++)
            cout << dec[i].second << " ";
    }




    return 0;
}