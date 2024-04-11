#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, k, m;

    cin >> n >> k >> m;

    vector<int> arr (n), cnt (m);

    for (auto &it : arr)
    {
        cin >> it;
        cnt[it % m]++;
    }

    int rem = max_element (cnt.begin (), cnt.end ()) - cnt.begin ();

    if (cnt[rem] < k)
        cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;

        for (int i = 0; k > 0; i++)
            if (arr[i] % m == rem)
            {
                cout << arr[i] << ' ';
                k--;
            }

        cout << endl;
    }

    return 0;
}