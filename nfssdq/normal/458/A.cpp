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

string s1, s2;
LL ar[300001], ar1[300001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z;
    cin >> s1 >> s2;
    for(int i = s1.size(); i >= 0; i--){
        a = s1.size() - 1 - i;
        ar[a] = s1[i] - '0';
    }
    for(int i = s2.size(); i >= 0; i--){
        a = s2.size() - 1 - i;
        ar1[a] = s2[i] - '0';
    }
    for(int i = 200000; i >= 0; i--){
        a = min(ar[i], ar1[i]);
        ar[i] -= a;
        ar1[i] -= a;
        if(ar[i] > 200000){
            cout << ">" << endl;
            return 0;
        }
        if(ar1[i] > 200000){
            cout << "<" << endl;
            return 0;
        }
        if(i > 1) {
            ar[i - 1] += ar[i];
            ar[i - 2] += ar[i];
            ar1[i - 1] += ar1[i];
            ar1[i - 2] += ar1[i];
            ar[i] = ar1[i] = 0;
        }
    }
    double p = (sqrt(5.0) + 1) / 2.0;
    double r1 = p*(double)ar[1] + (double)ar[0];
    double r2 = p*(double)ar1[1] + (double)ar1[0];
    if(r1 > r2) cout << ">" << endl;
    else if(r1 < r2) cout << "<" << endl;
    else cout << "=" << endl;
}
/*
q
q+1
2q+1
3q+2
5q+3
8q+5
*/