#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int m[2];
        m[0]=0, m[1]=0;
        for (int i=0; i<2; i++) {
            int a;
            cin >> a;
            for (int j=0; j<a; j++) {
                int x;
                cin >> x;
                m[i]=max(m[i], x);
            }
        }
        cout << (m[0]>=m[1] ? "Alice" : "Bob") << "\n";
        cout << (m[0]>m[1] ? "Alice" : "Bob") << "\n";
    }
    return 0;
}