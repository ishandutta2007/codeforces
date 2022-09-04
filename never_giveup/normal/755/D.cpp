/*
ID: ramil-p1
PROG: balancing
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const int maxn = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7;

int n, k;

ll q[maxn];

void inc(int i){
    for (; i < n; i = (i | (i + 1)))
        q[i]++;
}

int sum(int i){
    int ret = 0;
    for (; i >= 0; i = ((i & (i + 1)) - 1))
        ret += q[i];
    return ret;
}

int sum(int l, int r){
    if (l > r)
        return 0;
    return sum(r) - (l == 0 ? 0 : sum(l - 1));
}

int main(){
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    cin >> n >> k;
    int x = 0;
    ll answer = 1;
    for (int iter = 0; iter < n; iter++){
        if (k <= n / 2){
            int y = (x + k);
            answer++;
            if (y < n)
                answer += sum(x + 1, y - 1);
            else{
                y -= n;
                answer += sum(x + 1, n - 1) + sum(0, y - 1);
            }
            inc(x);
            inc(y);
            x = y;
            cout << answer << ' ';
        }
        else{
            int y = (x + k);
            answer++;
            if (y < n)
                answer += sum(0, x - 1) + sum(y + 1, n - 1);
            else{
                y -= n;
                answer += sum(y + 1, x - 1);
            }
            inc(x);
            inc(y);
            x = y;
            cout << answer << ' ';
        }
    }
}