#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e6;

vector <int> primes[MAXN + 1];
bool ciur[MAXN + 1];

inline void prec(int x2) {
    for(int i = 2; i <= x2; i++) {
        if(ciur[i] == 0) {
            for(int j = i; j <= x2; j += i) {
                primes[j].push_back(i);
                ciur[j] = 1;
            }
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int x2;
    ios::sync_with_stdio(false);
    cin >> x2;
    prec(x2);
    int ans = MAXN + 1;
    for(auto it2 : primes[x2]) {
        for(int x1 = 1; x1 <= x2; x1++) {
            if(((x1 + it2 - 1) / it2) * it2 == x2) {
                for(auto it1 : primes[x1]) {
                    if((x1 / it1) * it1 - it1 + 1 >= 3)
                        ans = min(ans, (x1 / it1) * it1 - it1 + 1);
                //if(ans == 1)
                  //  printf("%d %d %d\n" ,it2,x1,it1);
                }
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}