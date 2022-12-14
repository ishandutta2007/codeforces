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

LL ar[30][30], on[30];
string ss[111];
int main() {
    ios_base:: sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 1,g,h = 0,x,y,z = 0;
    cin >> a;
    REP(i, a) cin >> ss[i];
    FOR(i, 1, a){
        for(int j = 0; j < ss[i].size() + 1; j++){
            if(j >= ss[i].size() && j < ss[i - 1].size()){
                cout << "Impossible" << endl;
                return 0;
            }
            if(j >= ss[i].size()) continue;
            if(j >= ss[i - 1].size()) break;
            if(ss[i][j] == ss[i - 1][j]) continue;
            b = ss[i][j] - 'a';
            c = ss[i - 1][j] - 'a';
            if(ar[b][c] == 1) {
                cout << "Impossible" << endl;
                return 0;
            }
            ar[b][c] = -1;
            ar[c][b] = 1;
            break;
        }
    }
    string ret = "";
    for(int i = 0; i < 26; i++){
        c = -1;
        for(int j = 0; j < 26; j++){
            if(on[j]) continue;
            d = 0;
            for(int k = 0; k < 26; k++){
                if(ar[j][k] == -1){
                    d = 1;
                    break;
                }
            }
            if(d == 0){
                c = j;
                break;
            }
        }
        if(c == -1){
            cout << "Impossible" << endl;
            return 0;
        }
        on[c] = 1;
        ret += 'a'+c;
        REP(j, 26){
            if(ar[c][j] == 1) ar[j][c] = 0;
        }
    }
    cout << ret << endl;
}