#include <bits/stdc++.h>

using namespace std;
int w, n;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        n=a.size();
        int pos=0, pos2=-1;
        for (int i=1; i<n; i++) {
            if (a[i]<a[i-1]) {
                pos=i, pos2=i-1;
                break;
            }
        }
        if (pos) {
            for (int i=pos; i<n; i++) {
                if (a[i]<=a[pos]) {
                    pos=i;
                }
                while (pos2>=0 && a[pos]<a[pos2]) {
                    pos2--;
                }
            }
            pos2++;
            swap(a[pos], a[pos2]);
        }
        if (a<b) {
            cout << a << "\n";
        } else {
            cout << "---\n";
        }
    }
    return 0;
}