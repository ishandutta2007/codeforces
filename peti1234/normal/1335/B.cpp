#include <bits/stdc++.h>

using namespace std;
int w, n, a, b;
char c='a';
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> a >> b;
        c='a', c--;
        for (int i=1; i<=n; i++) {
            c++;
            cout << c;
            if (i%b==0) c-=b;
        }
        cout << endl;
    }
    return 0;
}