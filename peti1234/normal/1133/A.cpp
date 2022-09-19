#include <bits/stdc++.h>

using namespace std;
int x;
string a;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0; i<2; i++) {
        cin >> a;
        x+=(a[0]-'0')*600+(a[1]-'0')*60+(a[3]-'0')*10+(a[4]-'0');
    }
    x/=2;
    cout << x/600;
    x%=600;
    cout << x/60;
    x%=60;
    cout << ":";
    cout << x/10;
    x%=10;
    cout << x << "\n";
    return 0;
}