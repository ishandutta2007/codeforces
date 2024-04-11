#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;

int main()
{
    int n, l1, l2, l3;
    vector<int> a;
    cin >> n;
    cout << "? 1 2" << endl;
    cin >> l1;
    cout << "? 2 3" << endl;
    cin >> l2;
    cout << "? 1 3" << endl;
    cin >> l3;
    int a2 = l1 + l2 - l3;
    int a1 = l1 - a2, a3 = l2 - a2;
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);
    for (int i = 4; i <= n; i++)
    {
        cout << "? " << i - 1 << " " << i << endl;
        cin >> l1;
        a2 = l1 - a3;
        a.push_back(a2);
        a3 = a2;
    }
    cout << "! ";
    for (auto v : a)
        cout << v << " ";
}