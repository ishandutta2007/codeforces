#include<iostream>
#include<vector>

using namespace std;
typedef pair <int, int> pii;
const int N = 200000;

vector <int> ver[N];
vector <pii> edges;

int main()
{
    ios_base::sync_with_stdio(true);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ver[x].push_back(i);
    }
    if (ver[0].size() != 1)
    {
        cout << "-1" << endl;
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        long long coef;
        if (i == 1) coef = k; else coef = k - 1;
        if (ver[i].size() > coef * ver[i - 1].size())
        {
            cout << "-1" << endl;
            return 0;
        }
        int l = 0;
        for (int j = 0; j < ver[i - 1].size(); j++) for (int x = 1; x <= coef; x++)
        {
            if (l == ver[i].size()) break;
            edges.push_back(make_pair(ver[i - 1][j], ver[i][l]));
            l++;
        }
    }
    cout << edges.size() << endl;
    for (int i = 0; i < edges.size(); i++) cout << edges[i].first << " " << edges[i].second << endl;
    return 0;
}