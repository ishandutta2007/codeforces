#include <bits/stdc++.h>
#define MAXN 40

using namespace std;

string str;
bool v[MAXN + 1];

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int i,n,p;
    cin >> n >> p;
    long long tot = 0;
    for(i = 1; i <= n; i++) {
        str.clear();
        cin >> str;
        if(str.size() == 4)
            v[i] = 0;
        else
            v[i] = 1;
        tot += (1LL << (i - 1)) * v[i];
    }
    long long ans = 0;
    for(i = 1; i <= n; i++) {
        ans += 1LL * tot * p / 2;
        tot -= (tot + v[i]) / 2;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}