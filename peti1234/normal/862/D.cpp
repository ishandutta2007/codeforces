#include <bits/stdc++.h>;

using namespace std;
int n;
int a;
int b;
int p=1;
bool v[1001];
int l[16];
void ker(int k, int v, int m)
{
    cout << '?' << " ";
    for (int i=1; i<=n; i++) {
        if (i>=k && i<=v) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
    fflush(stdout);
    cin >> l[p];
    p++;
    if (m==0) {
       if (l[1]-l[p-1]==v-k+1) {
            a=k;
            return;
       }
       if (-l[1]+l[p-1]==v-k+1) {
            int j=v-k+1;
            k=v+1;
            v=k+j/2;
            ker(k, v, 0);
       } else {
            ker(k, (k+v)/2, 0);
       }
    }
    if (m==1) {
        if (-l[1]+l[p-1]==v-k+1) {
            b=k;
            return;
       }
       if (l[1]-l[p-1]==v-k+1) {
            int j=v-k+1;
            k=v+1;
            v=k+j/2;
            ker(k, v, 1);
       } else {
            ker(k, (k+v)/2, 1);
       }
    }
}
int main()
{
    cin >> n;
    cout << '?' << " ";
    for (int i=1; i<=n; i++) {
        cout << v[i];
    }
    cout << endl;
    fflush(stdout);
    cin >> l[p];
    p++;
    v[n]=1;
    cout << '?' << " ";
    for (int i=1; i<=n; i++) {
        cout << v[i];
    }
    cout << endl;
    fflush(stdout);
    cin >> l[p];
    p++;
    if (l[1]>l[2]) {
        a=n;
        ker(1, n-1, 1);
    } else {
        b=n;
        ker(1, n-1, 0);
    }
    cout << '!' << " " << b << " " << a << endl;
    fflush(stdout);
    return 0;
}