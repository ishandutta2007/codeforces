#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
 
#define oo            (int)13e7
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;
const int mxn = 10007;
int n, k;
char a[mxn];
char b[mxn];

int cnt[mxn];
int use[mxn];

pair<int,string> solve(int dig) {
    fill(cnt, 0); fill(use, 0); int left = k;
    for (int i=0; i < n; i++) {
        cnt[ a[i] - '0' ]++;
    }
    int ans = 0;
    for (int diff=0; diff <= 10; diff++) {
        if (diff == 0) {
            left -= (use[dig] = min(left, cnt[dig]));
        } else {
            int ndig = dig + diff;
            if (ndig <= 9) {
                int tmp = (use[ndig] = min(left, cnt[ndig]));
                left -= tmp;
                ans += diff * tmp;
            }
            ndig = dig - diff;
            if (ndig >= 0) {
                int tmp = (use[ndig] = min(left, cnt[ndig]));
                left -= tmp;
                ans += diff * tmp;
            }
        }
    }
    strcpy(b, a);
    for (int i=0; i < n; i++) {
        int cur = a[i] - '0';
        if (cur > dig && use[cur] > 0) {
            --use[cur];
            b[i] = dig + '0';
        }
    }
    for (int i=n-1; i >= 0; i--) {
        int cur = a[i] - '0';
        if (cur < dig && use[cur] > 0) {
            --use[cur];
            b[i] = dig + '0';
        }
    }
    return make_pair(ans, b);
}

int main(int argc, char** argv) {
	scanf("%d %d %s", &n, &k, a);
    pair<int, string> res((int)2e9, "");
    for (int u=0; u <= 9; u++)
        res = min(res, solve(u));
    printf("%d\n%s\n", res.first, res.second.c_str());
	return 0;
}