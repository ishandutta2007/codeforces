#include <bits/stdc++.h>

using namespace std;
int t[8], sum;
bool ch(int a, int b, int c) {
    return 2*(t[a]+t[b]+t[c])==sum;
}
int main()
{
    for (int i=1; i<=6; i++) cin >> t[i], sum+=t[i];
    sort(t+1, t+7);
    if (ch(1, 2, 6) || ch(1, 3, 6) || ch(1, 4, 5) || ch(1, 4, 6) || ch(1, 5, 6)) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}