#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> deck;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        deck.push_back(x);
    }
    reverse(deck.begin(), deck.end());
    while (q--)
    {
        int t;
        cin >> t;
        int ans = 1;
        auto it = deck.end();
        it--;
        while (*it != t)
        {
            it--;
            ans++;
        }
        cout << ans << " ";
        deck.erase(it);
        deck.push_back(t);
    }
    cout << "\n";
    return 0;
}