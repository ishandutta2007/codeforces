#include <iostream>
#include <string>

using namespace std;
const int ALPHA = 256;

bool used[ALPHA];

int main()
{
    string s;
    getline(cin, s);
    int d = s.length();
    for (int i = 0; i < d; i++) used[s[i]] = true;
    int ans = 0;
    for (int i = 97; i <= 122; i++) ans += used[i];
    cout << ans << endl;
    return 0;
}