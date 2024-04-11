#include <bits/stdc++.h>

using namespace std;
set<long long> s;
int main()
{
    ios_base::sync_with_stdio(false);
    s.insert(1);
    for (long long i=2; i<=40000; i++) {
        s.insert(i*i), s.insert(i*i*i);
    }
    int w;
    cin >> w;
    while (w--) {
        long long x;
        cin >> x;
        int db=0;
        for (auto p:s) {
            if (p<=x) db++;
        }
        cout << db << "\n";
    }
    return 0;
}