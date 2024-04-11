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


string s;
int ar[10];
set < int > S;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cin >> s;
    S.insert(7);
    S.insert(5);
    S.insert(2);
    S.insert(3);
    for(int i = 0; i < s.size(); i++){
        int a = s[i] - '0';
        for(int j = 2; j <= a; j++)ar[j]++;
    }
    string ret  = "";
    for(int i = 9; i >= 2; i--){
        if(S.count(i) > 0){
            while(ar[i]){
                for(int k = 2; k <= i; k++) ar[k]--;
                ret += i+'0';
            }
            continue;
        }
        for(int j = 2; j <= i; j++){
            if(i % j == 0){
                ar[j] += ar[i];
                ar[i / j] += ar[i];
                break;
            }
        }
    }
    cout << ret << endl;
}