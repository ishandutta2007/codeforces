#include <bits/stdc++.h>

using namespace std;
int a, ta, b, tb, ans;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> ta >> b >> tb >> s;
    int x=(s[0]-'0')*600+(s[1]-'0')*60-300+(s[3]-'0')*10+(s[4]-'0');
    for (int i=0; i<1140; i+=b) {
        if (i<x+ta && x<i+tb) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}