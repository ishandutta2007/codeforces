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
#define mod        100000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


string s, ret;
int on[10];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b = 0,c,d,e,f,g,h = 1,x,y,z;
    int ar[5] = {1, 6, 8, 9};
    cin >> s;
    ret = "";
    REP(i, s.size()){
        if(s[i] == '1' || s[i] == '6' || s[i] == '8' || s[i] == '9'){
            if(on[s[i] - '0'] == 1)goto p1;
            on[s[i] - '0'] = 1;
            goto p2;
        }
        p1:
        ret += s[i];
        b = ((b * 10) + s[i] - '0') % 7;
        p2:continue;
    }
    c = d = 0;
    REP(i, ret.size()){
        if(ret[i] == '0' && c == 0){
            d++;
            continue;
        }
        c = 1;
        cout << ret[i];
    }
    do{
        a = 0;
        REP(i, 4)a = (a*10 + ar[i]) % 7;
        if((a + b * 10000) % 7 == 0){
            REP(i, 4)cout <<ar[i];
            REP(i, d)cout << "0";
            cout << endl;
            return 0;
        }
    }while(next_permutation(ar, ar + 4));
}