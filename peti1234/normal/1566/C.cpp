#include <bits/stdc++.h>

using namespace std;
int w, n, sum, spec;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        sum=0, spec=0;
        for (int i=0; i<n; i++) {
            int x=(a[i]-'0'), y=(b[i]-'0');
            if (x>y) {
                swap(x, y);
            }
            if (y==0) {
                sum++;
                if (spec==2) {
                    sum++;
                    spec=0;
                } else {
                    spec=1;
                }
            } else if (x==1) {
                if (spec==1) {
                    sum++;
                    spec=0;
                } else {
                    spec=2;
                }
            } else {
                sum+=2;
                spec=0;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}