#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    cin >> w;
    while(w--) {
        int a, b;
        cin >> a >> b;
        if (a>b) swap(a, b);
        a=b-a;
        cout << (a+9)/10 << "\n";
    }
    return 0;
}