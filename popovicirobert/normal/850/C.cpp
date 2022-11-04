#include <bits/stdc++.h>
#define ll long long


using namespace std;

map <int, int> conf;

map <int, int> dp;

inline int grundy(int cnf) {
    int bit, i;
    if(dp.count(cnf) > 0)
        return dp[cnf];
    set <int> mex;
    for(bit = 0; (cnf >> bit) > 0; bit++)
        mex.insert(grundy((cnf >> (bit + 1)) | (cnf & ((1 << bit) - 1))));
    for(i = 0; ; i++)
        if(mex.count(i) == 0)
            return dp[cnf] = i;
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int d = 2;
        while(d * d <= x) {
            int e = 0;
            while(x % d == 0) {
                x /= d;
                e++;
            }
            if(e > 0)
                conf[d] |= (1 << (e - 1));
            d++;
        }
        if(x > 1)
            conf[x] |= 1;
    }
    int ans = 0;
    for(auto it : conf)
        ans ^= grundy(it.second);
    if(ans == 0)
        cout << "Arpa";
    else
        cout << "Mojtaba";
    //cin.close();
    //cout.close();
    return 0;
}