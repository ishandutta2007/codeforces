#include <bits/stdc++.h>
 
using namespace std;
int n;
string s;
long long x[2001];
long long y[2001];
bool v[2001];
int akt=1;
int f(int a, int b, int c)
{
    long long p=(x[b]-x[a])*(y[c]-y[a])-(x[c]-x[a])*(y[b]-y[a]);
    if (p>0) {
        return 1;
    }
    return -1;
}
void jk()
{
    int sol=0;
    for (int i=1; i<=n; i++) {
        if (!v[i] && ((sol==0) || f(akt, i, sol)==-1)) {
            sol=i;
        }
    }
    akt=sol;
    cout << akt << " ";
    v[akt]=true;
}
void bk()
{
    int sol=0;
    for (int i=1; i<=n; i++) {
        if (!v[i] && ((sol==0) || f(akt, i, sol)==1)) {
            sol=i;
        }
    }
    akt=sol;
    cout << akt << " ";
    v[akt]=true;
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
        if (x[i]<x[akt]) {
            akt=i;
        }
    }
    cin >> s;
    cout << akt << " ";
    v[akt]=true;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='R') {
            jk();
        } else {
            bk();
        }
    }
    jk();
    return 0;
}