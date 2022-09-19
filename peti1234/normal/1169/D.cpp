#include <bits/stdc++.h>
 
using namespace std;
int n;
bool v[300001];
int t[300001];
string s;
long long sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    n=s.size();
    for (int i=1; i<=n; i++) {
        t[i]=INT_MAX;
        char c;
        c=s[i-1];
        if (c=='1') {
            v[i]=1;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=20; j++) {
            if (i+2*j<=n) {
                if (v[i]==v[i+j] && v[i]==v[i+2*j]) {
                    t[i]=i+2*j;
                    break;
                }
            }
        }
    }
    for (int i=n-1; i>=1; i--) {
        t[i]=min(t[i], t[i+1]);
        if (t[i]!=INT_MAX) {
            sum+=n+1-t[i];
        }
    }
    cout << sum << endl;
    return 0;
}