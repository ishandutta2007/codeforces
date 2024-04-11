#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(true);
    int n, p, k;
    cin >> n >> p >> k;
    if (p - k > 1) cout << "<< ";
    for (int i = max(1, p - k); i < p; i++) cout << i << " ";
    cout << "(" << p << ")" << " ";
    for (int i = p + 1; i <= min(n, p + k); i++)
    {
        cout << i;
        if (i == n) continue;
        if (i == p + k) cout << " >>"; else cout << " ";
    }
    return 0;
}