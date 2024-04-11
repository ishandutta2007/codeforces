#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main ()
{
    int n, m, t;

    cin >> n >> m >> t;
    vector<pair<int, bool>> time (2 * n);

    for (int i = 0; i < n; i++)
    {
        int h, m, s;
        scanf ("%d:%d:%d", &h, &m, &s);

        time[i + n].first = (time[i] = make_pair (h * 60 * 60 + m * 60 + s, true)).first + t;
    }

    ios_base::sync_with_stdio (false);

    sort (time.begin (), time.end ());

    int ans = 0, open = m;
    bool g = false;
    vector<int> id;
    queue<int> ind;

    id.reserve (n);
    
    for (auto it : time)
    {
        if (it.second)
        {
            ind.push (id.size ());
            if (open)
            {
                open--;
                id.push_back (id.empty () ? 1 : id.back () + 1);
                ans++;

                if (open == 0)
                    g = true;
            }
            else
                id.push_back (id.back ());
        }
        else
        {
            if (id.size () == ind.front () + 1 || id[ind.front () + 1] != id[ind.front ()])
                open++;
            
            ind.pop ();
        }
    }

    if (!g)
    {
        cout << "No solution" << endl;

        return 0;
    }

    cout << ans << endl;

    for (auto it : id)
        cout << it << endl;

    return 0;
}