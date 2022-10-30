#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(true);
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    for (int i = 0; i < n; i++) if (s[i] == 'B') ans += 1LL << i;
    cout << ans << endl;
    return 0;
}