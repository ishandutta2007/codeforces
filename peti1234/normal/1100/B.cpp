#include <bits/stdc++.h>

using namespace std;
int t[100001];
int h[100001];
int f=1;
int n, m;
int main()
{
    cin >> m >> n;
    for (int i=1; i<=n; i++) {
        h[i]=m;
    }
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        t[x]++;
        h[t[x]]--;
        if (h[t[x]]==0) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    return 0;
}