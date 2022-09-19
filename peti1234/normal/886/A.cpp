#include <bits/stdc++.h>

using namespace std;
int sum, t[7], p, f;
int main()
{
    for (int i=1; i<=6; i++) cin >> t[i], sum+=t[i];
    sort(t+1, t+7), p=sum/2;
    if (t[1]+t[2]+t[6]==p || t[1]+t[3]+t[6]==p || t[1]+t[4]+t[6]==p || t[1]+t[5]+t[6]==p || t[1]+t[4]+t[5]==p) f++;
    if (f && sum%2==0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}