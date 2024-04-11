#include <cstdio>
#include <iostream>

using namespace std;
const long long BBP = 1e9 + 7;

int n, k;
long long d[2001][2005], sum[2005];
string s;

int main() {
    cin >> n >> k;
    cin >> s;
    
    d[0][0] = 1;
    sum[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            d[i][j] = (sum[j] * (int(s[i - 1]) - int('a'))) % BBP;
            
            int c = i - 1;
            while (c > 0 && (i - c) * (n - i + 1) <= j) {
                long long hz = (i - c) * (n - i + 1);
                
                d[i][j] = (d[i][j] + d[c][j - hz] * (int('z') - int(s[i - 1]))) % BBP;
                --c;
                
            }
            if (i * (n - i + 1) == j) {
                d[i][j] = (d[i][j] + (int('z') - int(s[i - 1]))) % BBP;
            }
            sum[j] = (sum[j] + d[i][j]) % BBP;
        }
    }   
    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = (ans + d[i][k]) % BBP;
    }

    cout << ans;

    return 0;
}