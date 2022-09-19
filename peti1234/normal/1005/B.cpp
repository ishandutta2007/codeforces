#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int sa=a.size(), sb=b.size();
    int db=0;
    for (int i=1; i<=min(sa, sb); i++) {
        if (a[sa-i]==b[sb-i]) {
            db++;
        } else {
            break;
        }
    }

    cout << sa+sb-2*db << "\n";
    return 0;
}