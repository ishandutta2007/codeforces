#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int sum=0;
        for (int i=0; i<6; i++) {
            char c;
            cin >> c;
            int x=c-'a';
            if (i<3) sum+=c;
            else sum-=c;
        }
        cout << (sum==0 ? "YES" : "NO") << "\n";
    }
    return 0;
}