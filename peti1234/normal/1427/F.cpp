#include <bits/stdc++.h>

using namespace std;
int ki[1202], t[1202], n, st, db, x;
bool g(int j) {
    return (j && t[ki[j]]==st%2);
}
bool ch(int j) {
    if (g(j-2) && g(j-1) && g(j)) {
        cout << ki[j-2] << " " << ki[j-1] << " " << ki[j] << "\n";
        db+=3;
        for (int k=j-2; k<=6*n-db; k++) ki[k]=ki[k+3];
        return 1;
    }
    return 0;
}
int main()
{
    cin >> n;
    for (int i=1; i<=3*n; i++) cin >> x, t[x]=1;
    for (int i=1; i<=6*n; i++) ki[i]=i;
    while(st<2*n) {
        st++;
        bool jo=0, cl=0;
        for (int i=2; i<=6*n-db; i++) {
            if (i%3!=1 && t[ki[i]]!=t[ki[i-1]]) cl=1;
            if (cl && !jo) jo=ch(i);
        }
        for (int i=3; i<=6*n-db; i++) if (!jo) jo=ch(i);
    }
    return 0;
}