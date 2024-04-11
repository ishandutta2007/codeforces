#include <bits/stdc++.h>

using namespace std;
int w, n, p, k;
string a, b;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> a >> b, p=0, k=0;
        for (int i=0; i<n; i++) {
            if (a[i]>b[i]) p++;
            if (b[i]>a[i]) k++;
        }
        if (p>k) cout << "RED\n";
        else if (k>p) cout << "BLUE\n";
        else cout << "EQUAL\n";
    }
    return 0;
}