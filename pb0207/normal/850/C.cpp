#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 100 + 10;

int n;
int a[N];
int mex[N];
map<int, int> sg;

void solve(long long x)
{
    if (sg.count(x)) return;

    vector<int> mex(30, 0);
    for(int i = 0; x >> i; ++ i) {
        long long nx = ((x >> (i + 1)) | (x & ((1 << i) - 1)));
        solve(nx);
        mex[sg[nx]] = 1;
    }
    int ret = 0;
    for( ; mex[ret]; ++ ret);
    sg[x] = ret;
}

int main()
{
    cin >> n;
    set<int> primes;
    for(int i = 0; i < n; ++ i) {
        cin >> a[i];
        int t = a[i];
        for(int j = 2; j * j <= t; ++ j) {
            if (t % j == 0) {
                primes.insert(j);
                while(t % j == 0) t /= j;
            }
        }
        if (t > 1) primes.insert(t);
    }

    sg[0] = 0;
    int ret = 0;
    for(auto e: primes) {
        int state = 0;
        for(int i = 0; i < n; ++ i) {
            int cnt = 0;
            while(a[i] % e == 0) {
                a[i] /= e;
                cnt ++;
            }
            if (cnt) state |= (1 << (cnt - 1));
        }
        //cout << e << ' ' << state << endl;
        solve(state);
        ret ^= sg[state];
    }
    //for(int i = 0; i < 5; ++ i) cout << i << ' ' << sg[i] << endl;

    cout << (ret ? "Mojtaba" : "Arpa") << endl;

	return 0;
}