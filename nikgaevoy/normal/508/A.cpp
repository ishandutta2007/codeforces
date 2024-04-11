#include <iostream>
#include <vector>

using namespace std;

class field
{
    vector<vector<bool>> f;

    bool cell_check (int y, int x)
    {
        return y < f.size () && y >= 0 && x >= 0 && x < f[0].size () && f[y][x];
    }

    bool square_check (int y, int x)
    {
        return cell_check (y, x) && cell_check (y + 1, x) && cell_check (y, x + 1) && cell_check (y + 1, x + 1);
    }

public:
    field (int n, int m) : f (n, vector<bool> (m))
    { }

    bool add (int y, int x)
    {
        if (f[y][x])
            return false;

        f[y][x] = true;

        return square_check (y, x) || square_check (y - 1, x) || square_check (y, x - 1) || square_check (y - 1, x - 1);
    }
};

int main ()
{
    std::ios_base::sync_with_stdio (false);

    int n, m, k;

    cin >> n >> m >> k;

    field mf(n, m);

    for (int cnt = 1; cnt <= k; cnt++)
    {
        int i, j;

        cin >> i >> j;

        if (mf.add (--i, --j))
        {
            cout << cnt << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}