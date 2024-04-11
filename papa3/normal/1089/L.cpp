#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v[100002];
set<pair<int, int> > s;
int task[100002], minut[100002];
int wsk[100002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++)
    {
        cin >> task[i];
    }
    for (int i=0; i<n; i++)
    {
        cin >> minut[i];
    }
    for (int i=0; i<n; i++)
        v[task[i]].push_back({minut[i], i});
    int il=0;
    for (int i=1; i<=k; i++)
    {
        sort(v[i].begin(), v[i].end());
        if (v[i].size()>0)
          il++;
        if (v[i].size()>1)
          s.insert(v[i][0]);
    }
    long long wyn=0;
    while (il<k)
    {
        int kto=(*s.begin()).second;
        s.erase(s.begin());
        wyn+=minut[kto];
        wsk[task[kto]]++;
        if (wsk[task[kto]]+1<v[task[kto]].size())
        {
            s.insert(v[task[kto]][wsk[task[kto]]]);
        }
        il++;
    }
    cout << wyn << "\n";
}