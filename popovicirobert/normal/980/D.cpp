#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXVAL = 10000;
const int MAXN = 5000;

int hsh[MAXN + 1];
char sign[MAXN + 1];

int sol[MAXN + 1];

bool ciur[MAXVAL + 1];
vector <int> primes;

bool f1[100000000], f2[100000000];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, x;
    ios::sync_with_stdio(false);
    for(i = 2; i * i <= MAXVAL; i++) {
        if(ciur[i] == 0) {
            for(int j = i * i; j <= MAXVAL; j += i)
                ciur[j] = 1;
        }
    }
    for(i = 2; i <= MAXVAL; i++) {
        if(ciur[i] == 0) {
            primes.push_back(i);
        }
    }
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x;
        if(x < 0)
            sign[i] = -1;
        if(x > 0)
            sign[i] = 1;
        x = abs(x);
        int val = 1;
        for(auto it : primes) {
            if(x <= 1)
                break;
            int e = 0;
            while(x % it == 0) {
                x /= it;
                e++;
            }
            if(e & 1)
                val *= it;
        }
        if(x > 1) {
            val *= x;
        }
        hsh[i] = val;
    }
    for(i = 1; i <= n; i++) {
        int cnt = 0;
        int nr = 0;
        for(j = i; j <= n; j++) {
            if(sign[j] == -1) {
                if(f1[hsh[j]] == 0)
                    nr++;
                f1[hsh[j]] = 1;
            }
            if(sign[j] == 1) {
                if(f2[hsh[j]] == 0)
                    nr++;
                f2[hsh[j]] = 1;
            }
            if(sign[j] == 0) {
                cnt++;
            }
            //printf("%d %d %d %d\n" ,i,j,nr,mp2[hsh[j].first]);
            if(cnt == j - i + 1)
                sol[1]++;
            else
                sol[nr]++;
        }
        for(j = i; j <= n; j++) {
            f1[hsh[j]] = f2[hsh[j]] = 0;
        }
    }
    for(i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}