#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, f, kov[c], ki[c];
bool v[c];
int holvan(int a) {
    return (ki[a]==a ? a : ki[a]=holvan(ki[a]));
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    ki[a]=b;
}
void dfs(int a, int kezd) {
    //cout << "dfs " << a << " " << kezd << "\n";
    v[a]=true;
    int x=2*a%n, y=x+1;
    int cel=(!v[x] || x==kezd ? x : y);
    //cout << "cel " << cel << "\n";
    kov[a]=cel;
    unio(a, cel);
    if (!v[cel]) dfs(cel, kezd);
}
int main()
{
    cin >> n;
    if (n%2) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i=0; i<n; i++) ki[i]=i;
    for (int i=0; i<n; i++) {
        if (!v[i]) {
            dfs(i, i);
        }
    }
    f=n/2;
    for (int i=0; i<f; i++) {
        //cout << "fontos " << i << " " << i+f << "\n";
        if (holvan(i)!=holvan(i+f)) {
            //cout << "valt\n";
            swap(kov[i], kov[i+f]);
            unio(i, i+f);
        }
    }
    //cout << "vege " << kov[0] << " " << kov[1] << "\n";
    int pos=0;
    for (int i=1; i<=n+1; i++) {
        cout << pos << " ";
        pos=kov[pos];
    }
    cout << "\n";
    return 0;
}