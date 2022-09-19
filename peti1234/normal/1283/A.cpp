#include <bits/stdc++.h>

using namespace std;
int w, a, b;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b;
        cout << (23-a)*60+(60-b) << "\n";
    }
    return 0;
}