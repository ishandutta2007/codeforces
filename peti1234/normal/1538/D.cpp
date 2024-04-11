#include <bits/stdc++.h>

using namespace std;
const int c=32000;
vector<int> pr;
bool h[c];
int w, a, b, k, db;
int main()
{
    for (int i=2; i<c; i++) {
        if (!h[i]) {
            pr.push_back(i);
            for (int j=i; j<c; j+=i) {
                h[j]=1;
            }
        }
    }
    cin >> w;
    for (int tc=1; tc<=w; tc++) {
        cin >> a >> b >> k;
        if (k==1) {
            cout << ((a%b==0) != (b%a==0) ? "YES" : "NO") << "\n";
        } else {
            db=0;
            for (auto x:pr) {
                while (a%x==0) {
                    a/=x;
                    db++;
                }
                while (b%x==0) {
                    b/=x;
                    db++;
                }
            }
            db+=(a>1)+(b>1);
            cout << (db>=k ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}