#include <bits/stdc++.h>

using namespace std;
int w, x;
vector<int> sz;
int main()
{
    for (int i=1; i<10000; i++) {
        if (i%10!=3 && i%3) {
            sz.push_back(i);
        }
    }
    cin >> w;
    while (w--) {
        int x;
        cin >> x;
        cout << sz[x-1] << "\n";
    }
    return 0;
}