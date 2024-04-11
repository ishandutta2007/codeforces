#include <bits/stdc++.h>

using namespace std;
int n, m;
int t[200001];
bool v[200001];
void kork(int d)
{
    while (v[d]==false) {
        v[d]=true;
        d=t[d];
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    int p=0;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x==1) {
            p++;
        }
    }

    kork(1);
    for (int i=2; i<=n; i++) {
        if (v[i]==false) {
            kork(i);
            m++;
        }

    }
    if (m!=0) {
        m++;
    }
    if (p%2==0) {
        m+=1;
    }
    cout << m << endl;
    return 0;
}