#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int n;
string s;


int main()
{
    cin >> n >> s;

    int ans = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        if(s[i] == s[i + 1])
        {
            ++ans;
        }
    }
    cout << ans;

    return 0;
}