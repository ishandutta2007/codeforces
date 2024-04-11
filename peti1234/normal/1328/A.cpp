#include <bits/stdc++.h>

using namespace std;
int w;
long long a, b;
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> b;
        cout << (b-a%b)%b << "\n";
    }
    return 0;
}
// Knny volt.