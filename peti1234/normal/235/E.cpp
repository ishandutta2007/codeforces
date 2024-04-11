#include <bits/stdc++.h>

using namespace std;
const int c=2002;
bool jo[c][c], sq[c];
long long ans, x, y, z, ert[c];
long long f(int a, int b) {
    int sum=0;
    for (int i=1; i<=a; i++) sum+=jo[i][b]*(a/i);
    return sum;
}
int main()
{
    cin >> x >> y >> z, jo[0][1]=1, jo[1][0]=1, ert[1]=1;
    for (int i=2; i<c; i++) for (int j=2; j<=i; j++) if (i%j==0) {ert[i]=-ert[i/j]; break;}
    for (int i=2; i*i<c; i++) for (int j=i*i; j<c; j+=i*i) sq[j]=1;
    for (int i=1; i<c; i++) for (int j=1; j<c; j++) {
        if (i>j) jo[i][j]=jo[i%j][j];
        else jo[i][j]=jo[i][j%i];
    }
    for (int i=1; i<c; i++) if (!sq[i]) for (int j=1; j<=x; j++) if (jo[i][j]) ans+=ert[i]*(x/j)*f(y/i, j)*f(z/i, j);
    cout << ans%(1<<30);
    return 0;
}