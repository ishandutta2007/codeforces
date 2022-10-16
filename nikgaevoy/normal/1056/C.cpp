#ifdef LOCAL
#include "stdafx.h"
#else
#include <bits/stdc++.h>
#endif // LOCAL


using namespace std;


mt19937 mt (736);


void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, m;

    cin >> n >> m;

    vector<int> p (2 * n);

    for (auto &it : p)
        cin >> it;

    vector<int> bros (2 * n, -1);
    vector<pair<int, int>> edges (m);

    for (auto &it : edges)
    {
        int a, b;

        cin >> a >> b;
        a--;
        b--;

        it = {a, b};
        bros[a] = b;
        bros[b] = a;
    }

    vector<bool> used (2 * n);

    int t, cnt = 2 * n;

    cin >> t;

    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < p.size (); i++)
        pq.emplace (p[i], i);

    int x = -1;

    while (cnt > 0)
    {
        if (t == 1)
        {
            if (x == -1 || bros[x] == -1 || used[bros[x]])
            {
                while (!edges.empty () && used[edges.back ().first])
                    edges.pop_back ();

                if (!edges.empty ())
                {
                    if (p[edges.back ().first] < p[edges.back ().second])
                    {
                        used[edges.back ().second] = true;
                        cout << edges.back ().second + 1 << endl;
                    }
                    else
                    {
                        used[edges.back ().first] = true;
                        cout << edges.back ().first + 1 << endl;
                    }
                }
                else
                {
                    while (used[pq.top ().second])
                        pq.pop ();

                    used[pq.top ().second] = true;
                    cout << pq.top ().second + 1 << endl;
                }
            }
            else
            {
                used[bros[x]] = true;

                cout << bros[x] + 1 << endl;
            }

            cout << flush;
        }
        else
        {
            assert (t == 2);

            cin >> x;

            if (x == -1)
                return;

            x--;

            used[x] = true;
        }

        t ^= 1 ^ 2;
        cnt--;
    }
}


int main ()
{
#ifdef LOCAL
    ifstream fin ("input.txt");

    solve ();

    cout << setprecision (4) << "clock: " << clock () / (double)CLOCKS_PER_SEC << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}