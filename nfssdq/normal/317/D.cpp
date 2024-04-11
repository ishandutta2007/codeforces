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

map < int, int > vis[33], res[33];
LL dp[30] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
LL go(int n, int bp){
    if(bp == (1<<n)-1) return 0;
    if(vis[n][bp] == 1) return res[n][bp];
    vis[n][bp] = 1;
    set < int > S;
    for(int i = 1; i <= n; i++){
        if(bp & 1<<(i-1)) continue;
        int tmp = bp;
        for(int j = i; j <= n; j += i) tmp |= 1<<(j - 1);
        S.insert(go(n, tmp));
    }
    for(int i = 0; ; i++){
        if(S.count(i) == 0) return res[n][bp] = i;
    }
}
int on[100001];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a;
    b = sqrt(a);
    d = 0;
    for(int i = 2; i <= b; i++){
        if(on[i] == 0){
            c = 1;
            d = 0;
            while(c*i <= a){
                c *= i;
                if(c <= b) on[c] = 1;
                e++;
                d++;
            }
            f ^= dp[d];
        }
    }
    b = a - e;
    if(b % 2 == 1) f ^= dp[1];
    if(f == 0) cout << "Petya" << endl;
    else cout << "Vasya" << endl;
}
/*
1 2 3
1
*/