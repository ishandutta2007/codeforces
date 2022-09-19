#include <bits/stdc++.h>

using namespace std;
int n;
int t[1000001];
bool v[1000001];
void ker(int i)
{
    if (v[i]) {
        return;
    }
    v[i]=true;
    ker(t[i]);
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    int f=0;
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            ker(i);
            f++;
        }
    }
    if (f%2==0) {
        cout << "Petr" << endl;
    } else {
        cout << "Um_nik" << endl;
    }
    return 0;
}