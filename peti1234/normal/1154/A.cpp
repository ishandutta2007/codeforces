#include <bits/stdc++.h>

using namespace std;
int t[4];
int main()
{
    for (int i=0; i<4; i++) cin >> t[i];
    sort(t, t+4);
    for (int i=0; i<3; i++) cout << t[3]-t[i] << " ";
    return 0;
}