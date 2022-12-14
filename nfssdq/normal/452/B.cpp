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

int dis(int a, int b, int c, int d){
    return (a-c)*(a-c) + (b-d)*(b-d);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f,g,h = 0,x,y,z;
    cin >> a >> b;
    if(a == 0){
        cout << "0 1" << endl;
        cout << 0 << " " << b << endl;
        cout << "0 0" << endl;
        cout << 0 << " " << b-1 << endl;
        return 0;
    }
    if(b == 0){
        cout << "1 0" << endl;
        cout << a << " " << 0 << endl;
        cout << "0 0" << endl;
        cout << a-1 << " " << 0 << endl;
        return 0;
    }
    e = x = y = z = 0;
    for(int i = 1; i <= b; i++){
        for(int j = 0; j < b; j++){
            c = dis(0,i,a,b)+dis(a,b,0,0)+dis(0,0,a,j);
            d = dis(0,0,a,b)+dis(a,b,0,i)+dis(0,i,a,j);
            if(c > e){
                e = c;
                x = i;
                y = j;
                z = 1;
            }
            if(d > e){
                e = d;
                x = i;
                y = j;
                z = 2;
            }
        }
    }
    for(int i = 1; i <= a; i++){
        for(int j = 0; j < a; j++){
            c = dis(i,0,a,b)+dis(a,b,0,0)+dis(0,0,j,b);
            d = dis(0,0,a,b)+dis(a,b,i,0)+dis(i,0,j,b);
            if(c > e){
                e = c;
                x = i;
                y = j;
                z = 3;
            }
            if(d > e){
                e = d;
                x = i;
                y = j;
                z = 4;
            }
        }
    }
    if(z == 1){
        cout << 0 << " " << x << endl;
        cout << a << " " << b << endl;
        cout << "0 0" << endl;
        cout << a << " " << y << endl;
    } else if(z == 2){
        cout << "0 0" << endl;
        cout << a << " " << b << endl;
        cout << 0 << " " << x << endl;
        cout << a << " " << y << endl;
    } else if(z == 3){
        cout << x << " " << 0 << endl;
        cout << a << " " << b << endl;
        cout << "0 0" << endl;
        cout << y << " " << b << endl;
    } else {
        cout << "0 0" << endl;
        cout << a << " " << b << endl;
        cout << x << " " << 0 << endl;
        cout << y << " " << b << endl;
    }
}