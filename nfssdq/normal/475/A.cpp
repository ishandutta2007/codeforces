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

int ar[11][4];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    if(a >= 4) {
        REP(j, 4) ar[0][j] = 1;
        a -= 4;
    } else {
        REP(j, a) ar[0][j] = 1;
        a = 0;
    }
    cout << "+------------------------+" << endl;
    b = 1;
    while(a > 0){
        REP(i, min(3ll, a)) ar[b][i] = 1;
        b++;
        if(a >= 3) a -= 3;
        else a = 0;
    }
    FOR(i, 1, 11) swap(ar[i][2], ar[i][3]);
    REP(i, 4){
        cout << "|";
        if(i == 2){
            if(ar[0][2] == 1) cout << "O.";
            else cout << "#.";
            REP(i, 11) cout << "..";
            cout << "|";
            cout << endl;
            continue;
        }
        REP(j, 11){
            if(ar[j][i] == 1) cout << "O.";
            else cout << "#.";
        }
        cout << "|";
        if(i == 0) cout << "D";
        else cout << ".";
        if(i != 1) cout << "|)";
        else cout << "|";
        cout << endl;
    }
    cout << "+------------------------+" << endl;
}