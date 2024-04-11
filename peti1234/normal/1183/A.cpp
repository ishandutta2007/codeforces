#include <bits/stdc++.h>

using namespace std;
int s(int x) {
    int ans=0;
    while (x) {
        ans+=(x%10);
        x/=10;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int x;
    cin >> x;
    while (s(x)%4) {
        x++;
    }
    cout << x << "\n";
    return 0;
}