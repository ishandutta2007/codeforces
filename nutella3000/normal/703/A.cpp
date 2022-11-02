#include<bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif

    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0;i < n;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        if (v1 > v2) cnt++;
        if (v2 > v1) cnt--;
    }
    if (cnt == 0) cout << "Friendship is magic!^^";
    if (cnt > 0) cout << "Mishka";
    if (cnt < 0) cout << "Chris";
}