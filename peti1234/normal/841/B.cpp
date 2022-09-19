#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x=0;
        cin >> x;
        if (x%2!=0) {
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
    return 0;
}