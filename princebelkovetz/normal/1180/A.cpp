#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int cur = 0, ans = 1;
    for (int i = 1; i <= n; ++i, cur += 4){
        ans += cur;
    }
    cout << ans << '\n';
    return 0;
}