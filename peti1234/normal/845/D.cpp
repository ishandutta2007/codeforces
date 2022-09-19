#include <bits/stdc++.h>

using namespace std;
stack<int> k;
int h;
int n;
int m;
int s;
int main()
{
    cin >> n;
    k.push(INT_MAX);
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        if (a==1) {
            int b;
            cin >> b;
            s=b;
            while (b>k.top()) {
                h++;
                k.pop();
            }
        }
        if (a==2) {
            h+=m;
            m=0;
        }
        if (a==3) {
            int b;
            cin >> b;
            if (s>b) {
                h++;
            } else {
                k.push(b);
            }
        }
        if (a==4) {
           m=0;
        }
        if (a==5) {
            k.push(INT_MAX);
        }
        if (a==6) {
            m++;
        }
    }
    cout << h<< endl;
    return 0;
}