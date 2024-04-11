#include <bits/stdc++.h>

using namespace std;
vector<int> num={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a, b, ans;
int main()
{
    cin >> a >> b;
    for (int i=a; i<=b; i++) {
        int s=i;
        while (s) {
            ans+=num[s%10];
            s/=10;
        }
    }
    cout << ans << "\n";
    return 0;
}