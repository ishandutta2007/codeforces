#include <bits/stdc++.h>
 
using namespace std;
int n, m;
int t[300001];
int a=-1, b=300001;
bool ker(int c)
{
    if (c>m) {
        return true;
    }
    int prev=0;
    for (int i=1; i<=n; i++) {
        int p=t[i];
        if (prev-p>c) {
            return false;
        }
        if (p>=prev) {
            if (p+c<m ||(p+c)%m<prev) {
                prev=p;
            }
        }
 
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    while(b-a>1) {
        int c=(a+b)/2;
        if (ker(c)) {
            b=c;
        } else {
            a=c;
        }
    }
    cout << b << endl;
    return 0;
}