#include <bits/stdc++.h>

using namespace std;

struct Pt
{
    int x, y;
    long long dot(const Pt& other) const { return (long long) x * other.x + (long long) y * other.y; };
    Pt operator-(const Pt& other) const { return {x - other.x, y - other.y}; };
    friend ostream& operator<<(ostream& os, const Pt& p) { os << "(" << p.x << "," << p.y << ")"; return os; };
};

const int MAXN = 5000;
Pt a[MAXN + 1];
int ans[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = i;
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    for (int i = 1; i + 2 <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            Pt first = a[ans[j]];
            Pt second = a[ans[j + 1]];
            Pt third = a[ans[j + 2]];
            Pt v1 = second - first; //a[i + 1] - a[i];
            Pt v2 = third - second; //a[i + 2] - a[i + 1];
            if (v1.dot(v2) >= 0)
                swap(ans[j + 1], ans[j + 2]);
            else
                break;
        }

        //cout << "dotting" << endl;
        //cout << v1 << endl;
        //cout << v2 << endl;

    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
    return 0;
}