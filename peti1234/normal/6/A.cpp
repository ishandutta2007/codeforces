#include <bits/stdc++.h>

using namespace std;
int t[5];
int main()
{
    for (int i=1; i<=4; i++) cin >> t[i];
    sort(t+1, t+5);
    if (t[1]+t[2]>t[3] || t[2]+t[3]>t[4]) cout << "TRIANGLE\n";
    else if (t[1]+t[2]==t[3] || t[2]+t[3]==t[4]) cout << "SEGMENT\n";
    else cout << "IMPOSSIBLE\n";
    return 0;
}