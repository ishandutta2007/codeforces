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
#define PI         2.0*acos(0.0)
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

LL ar[100001], bit[100001];
void insert(int id, int v){
    for(int i = id; i <= 100000; i += i & -i) bit[i] += v;
}
LL query(int id){
    LL ret = 0;
    for(int i = id; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b;
    FOR(i, 1, a + 1) ar[i] = 1;
    FOR(i, 1, a + 1) insert(i, 1);
    int l = 1, r = a, n = a;
    REP(ts, b){
        cin >> c;
        if(c == 1){
            cin >> d;
            e = n - d;
            if(e >= d){
                if(l <= r){
                    f = l + d;
                    for(int i = l + d - 1; i >= l; i--){
                        insert(f, ar[i]);
                        ar[f++] += ar[i];
                        n--;
                    }
                    l += d;
                } else {
                    f = l - d;
                    for(int i = l - d + 1; i <= l; i++){
                        insert(f, ar[i]);
                        ar[f--] += ar[i];
                        n--;
                    }
                    l -= d;
                }
            } else {
                if(l <= r){
                    f = r - e;
                    for(int i = r - e + 1; i <= r; i++){
                        insert(f, ar[i]);
                        ar[f--] += ar[i];
                        n--;
                    }
                    r -= e;
                    swap(l, r);
                } else {
                    f = r + e;
                    for(int i = r + e - 1; i >= r; i--){
                        insert(f, ar[i]);
                        ar[f++] += ar[i];
                        n--;
                    }
                    r += e;
                    swap(l, r);
                }
            }
        } else {
            cin >> d >> e;
//            cout << l << " " << r << endl;
            if(l <= r){
                cout << query(l + e - 1) - query(l + d - 1) << endl;
            } else {
                cout << query(l - d) - query(l - e) << endl;
            }
        }
//        cout << l << " " << r << endl;
    }
}