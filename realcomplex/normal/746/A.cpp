#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second


int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int s[3];
    s[0] = a;
    s[1] = b/2;
    s[2] = c/4;
    sort(s,s+3);
    cout << s[0]*7;
    return 0;
}