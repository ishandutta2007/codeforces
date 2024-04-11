#include <bits/stdc++.h>

using namespace std;
const int c=1<<22;
int regi[c], uj[c], maxi, n, x, y, s;
bool jo[c];
int main()
{
    cin >> n >> x >> y;
    for (int j=0; j<c; j++) {
        if ((j & (1<<x-1))==0 && ((j &(1<<y-1))==0)) {
            jo[j]=1;
        }
    }
    s=x+y;
    for (int i=0; i<s; i++) {
        int db=(n+s-i-1)/s;
        for (int j=0; j<c; j++) {
            regi[j]=uj[j];
            uj[j]=0;
        }
        for (int j=0; j<c; j++) {
            int p=2*j;
            if (p>=c) {
                p-=c;
            }
            uj[p]=max(uj[p], regi[j]);
            if (jo[j]) {
                uj[p+1]=max(uj[p+1], regi[j]+db);
            }
        }
    }
    for (int j=0; j<c; j++) {
        maxi=max(maxi, uj[j]);
    }
    cout << maxi << "\n";
    return 0;
}