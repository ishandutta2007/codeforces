#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        long long n, k;
        cin >> n >> k;
        if (n%2==k%2 && n>=k*k) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}