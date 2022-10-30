#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef pair <int, int> pii;

vector <pii> ma, mb;
int a, b;

bool check(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 || y1 == y2) return false;
    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) != a * a + b * b) return false;
    cout << "YES" << endl;
    cout << 0 << " " << 0 << endl;
    cout << x1 << " " << y1 << endl;
    cout << x2 << " " << y2 << endl;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(true);
    cin >> a >> b;
    for (int i = 1; i <= 1000; i++) for (int j = 1; j <= 1000; j++) if (i * i + j * j == a * a) ma.push_back(make_pair(i, j));
    if (ma.size() == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 1; i <= 1000; i++) for (int j = 1; j <= 1000; j++) if (i * i + j * j == b * b) mb.push_back(make_pair(i, j));
    if (mb.size() == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < ma.size(); i++) for (int j = 0; j < mb.size(); j++)
    {
        if (check(-ma[i].first, ma[i].second, mb[j].first, mb[j].second)) return 0;
        if (check(-ma[i].second, ma[i].first, mb[j].first, mb[j].second)) return 0;
        if (check(-mb[j].first, mb[j].second, ma[i].first, ma[i].second)) return 0;
        if (check(-mb[j].second, mb[j].first, ma[i].first, ma[i].second)) return 0;
    }
    cout << "NO" << endl;
    return 0;
}