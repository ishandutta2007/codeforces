#include <bits/stdc++.h>

using namespace std;
const int cc=20000002;
int prdb[cc];
long long w, c, d, x, ans;
void ch(long long s) {
    long long cel=x+d*s;
    if (cel%(c*s)==0) {
        cel/=c*s;
        ans+=(1<<prdb[cel]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=2; i<cc; i++) {
        if (!prdb[i]) {
            for (int j=i; j<cc; j+=i) {
                prdb[j]++;
            }
        }
    }
    cin >> w;
    while (w--) {
        cin >> c >> d >> x;
        ans=0;
        for (int i=1; i*i<=x; i++) {
            if (x%i==0) {
                ch(i);
                if (i*i!=x) {
                    ch(x/i);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
1
1 1 3
*/