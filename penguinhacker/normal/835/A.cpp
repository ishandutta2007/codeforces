#include <bits/stdc++.h>
using namespace std;

int s, v1, v2, t1, t2;
int tot1, tot2;

int main() {
    cin >> s >> v1 >> v2 >> t1 >> t2;
    tot1 = 2*t1 + s*v1;
    tot2 = 2*t2 + s*v2;
    if (tot1 == tot2)
        cout << "Friendship";
    else if (tot1 < tot2)
        cout << "First";
    else
        cout << "Second";
    return 0;
}