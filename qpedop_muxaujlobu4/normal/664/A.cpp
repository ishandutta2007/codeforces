#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string s, s1;
    cin >> s >> s1;
    if (s == s1)cout << s;
    else cout << 1;
    return 0;
}