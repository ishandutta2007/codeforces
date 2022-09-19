#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n, db=0;
        cin >> n;
        while(n>1) {
            if (n%3) {
                db=-1;
                break;
            }
            while(n%6==0) n/=6, db++;
            if (n>1) n*=2, db++;
        }
        cout << db << "\n";
    }
    return 0;
}