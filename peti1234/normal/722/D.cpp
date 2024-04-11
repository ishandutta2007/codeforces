#include <bits/stdc++.h>

using namespace std;
set<int,greater<int>> t;
int n;
int k=1;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        t.insert(x);
    }
    while (k!=0) {
        k=*t.begin();
        while (t.find(k)!=t.end()) {
            k=k/2;


        }
        if (k!=0) {
            t.erase(t.begin());
            t.insert(k);
        }
    }
    for (int i : t) {
        cout << i << " ";
    }
    return 0;
}