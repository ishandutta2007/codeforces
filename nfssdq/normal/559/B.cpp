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

#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>
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

string s1, s2;

int go(int l1, int r1, int l2, int r2){
    int fl = 0, p = l2;
    for(int i = l1; i <= r1; i++){
        if(s1[i] != s2[p++]) fl = 1;
    }
    if(fl == 0) return 1;

    if((r1-l1) % 2 == 0) return 0;

    int m1 = (r1 + l1) / 2;
    int m2 = (r2 + l2) / 2;

    int v11 = go(l1, m1, l2, m2);
    if(v11 == 0){
        int v21 = go(l1, m1, m2 + 1, r2);
        if(v21 == 0) return 0;
        return go(m1 + 1, r1, l2, m2);
    }
    int v12 = go(m1 + 1, r1, m2 + 1, r2);
    if(v12 == 0){
        int v22 = go(m1 + 1, r1, l2, m2);
        if(v22 == 0) return 0;
        return go(l1, m1, m2 + 1, r2);
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s1 >> s2;

    if(go(0, s1.size()-1, 0, s1.size()-1)) cout << "YES" << endl;
    else cout << "NO" << endl;
}