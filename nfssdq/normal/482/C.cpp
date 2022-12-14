/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

double dp[1<<21], cnt[1<<21];
string S[55];
LL bit[1<<21];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    REP(i, a) cin >> S[i];
    b = S[0].size();
    REP(i, a){
        REP(j, a){
            if(i == j) continue;
            c = 0;
            REP(k, b){
                if(S[i][k] == S[j][k]) c |= 1<<k;
            }
            bit[c] |= 1ll<<i;
        }
    }
    for(int i = (1<<b) - 1; i >= 0; i--){
        REP(j, b){
            if(i & 1<<j) continue;
            bit[i] |= bit[i | 1<<j];
        }
        cnt[i] = __builtin_popcountll(bit[i]);
    }
    if(a > 1) cnt[0] = a;
    else cnt[0] = 0;
    for(int i = (1<<b) - 2; i >= 0; i--){
        if(cnt[i] == 0) continue;
        double p = cnt[i] * (double)(b - __builtin_popcount(i));
        REP(j, b){
            if(i & 1<<j) continue;
            dp[i] += dp[i | 1<<j] * cnt[i | 1<<j] / p;
        }
        dp[i] += 1;
    }
    cout << fixed << setprecision(10) << dp[0] << endl;
}
/*
10
aababbbaabaababababa
ababaababbabaaababbb
ababbababaaaaaabbbab
ababbbbabaabaaababaa
abbabbbaabbbbbbbaaba
baaabbabababbabbaaaa
bababbbbbbaaaabbaaba
babbaabaaabaaaabbaab
babbbaababaabbbbbaab
bbbbabaaababaabbabab
*/