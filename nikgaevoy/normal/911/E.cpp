#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>

#include <cassert>
#include <cmath>

using namespace std;

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, k;

    cin >> n >> k;

    vector<int> arr (k), ans (n);

    for (auto &it : arr)
        cin >> it;

    copy (arr.begin (), arr.end (), ans.begin ());

    stack<int> st;

    int u = 1;

    for (auto it : arr)
    {
        if (!st.empty () && st.top () < it)
        {
            cout << -1 << endl;

            return;
        }

        st.push (it);

        while (!st.empty () && st.top () == u)
        {
            st.pop ();
            u++;
        }
    }

    for (int i = k; i < n; i++)
    {
        st.push (ans[i] = st.empty () ? n : st.top () - 1);

        while (!st.empty () && st.top () == u)
        {
            st.pop ();
            u++;
        }
    }

    for (auto it : ans)
        cout << it << ' ';
    cout << endl;
}

int main ()
{
    solve ();

    return 0;
}