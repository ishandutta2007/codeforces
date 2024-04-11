#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        bool jo=((n%2021)==0);
        while(n>0) {
            n-=2020;
            if (n%2021==0) {
                jo=1;
            }
        }
        cout << (jo ? "YES" : "NO") << endl;
    }
    return 0;
}