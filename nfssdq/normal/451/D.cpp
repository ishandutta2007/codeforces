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

LL ar[100001], even[100011], odd[100011], odR[100011], evR[100011];
LL oc[100011], ec[100011];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z;
    string S;
    cin >> S;
    REP(i, S.size()){
        if(i > 0 && S[i - 1] != S[i]) d++;
        ar[d]++;
    }
    d++;
    REP(i, d){
        odd[i] = (ar[i] + 1)/2;
        even[i] = ar[i]/2;
    }
    for(int i = 1; i <= 100000; i++){
        oc[i] = ((i + 1) / 2) + oc[i - 1];
        ec[i] = (i / 2) + ec[i - 1];
    }
    g = h = 0;
    for(int i = d - 1; i >= 0; i--) {
        e = even[i];
        f = odd[i];
        odR[i] += f;
        evR[i] += e;
        z = ar[i] + ar[i + 1];
        if(ar[i + 1] % 2 == 0){
            g += odd[i]*evR[i + 2] + even[i]*odR[i + 2];
            h += odd[i]*odR[i + 2] + even[i]*evR[i + 2];
        } else {
            h += odd[i]*evR[i + 2] + even[i]*odR[i + 2];
            g += odd[i]*odR[i + 2] + even[i]*evR[i + 2];
        }
        g += oc[ar[i]];
        h += ec[ar[i]];
        if(z % 2 == 0){
            odR[i] += odR[i + 2];
            evR[i] += evR[i + 2];
        } else {
            odR[i] += evR[i + 2];
            evR[i] += odR[i + 2];
        }
    }
    cout << h << " " << g << endl;
}