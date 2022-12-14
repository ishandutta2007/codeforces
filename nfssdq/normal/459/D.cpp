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

LL cnt[1000001], ar[1000001], sumL[1000001], sumR[1000001];
map < int, int > mm;
LL bit[1000001];
void insert(int x){
    for(int i = x; i <= 1000000; i += i & -i) bit[i]++;
}
LL query(int x){
    LL ret = 0;
    for(int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f,g,h = 0,x,y,z;
    cin >> a;
    FOR(i, 1, a + 1){
        cin >> ar[i];
        mm[ar[i]] = 1;
    }
    b = 0;
    for(map < int, int >::iterator it = mm.begin(); it != mm.end(); it++){
        (*it).yy = ++b;
    }
    FOR(i, 1, a + 1){
        ar[i] = mm[ar[i]];
    }
    for(int i = 1; i <= a; i++){
        cnt[ar[i]]++;
        sumL[i] = cnt[ar[i]];
    }
    set0(cnt);
    for(int i = a; i >= 1; i--){
        cnt[ar[i]]++;
        sumR[i] = cnt[ar[i]];
    }
//    cout << "ppp" << endl;
    c = 0;
    for(int i = a; i >= 1; i--){
        c += query(sumL[i] - 1);
        insert(sumR[i]);
    }
    cout << c << endl;
}