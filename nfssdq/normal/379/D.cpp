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
#define mod        1000003ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


LL ar[3][11];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f = 0,g,h = 1,x,y,z;
    cin >> a >> b >> c >> d;
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            for(int k = 0; k <= 2; k++){
                for(int p = 0; p <= 2; p++){
                    for(int n = 0; n <= 50; n++){
                        if(n * 2 > c)continue;
                        if(c == 1 && i != j)continue;
                        if(n * 2 == c && (i != 0 || j != 1))continue;
                        if(c != 1 && n * 2 == (c - 1) && (i != 0 && j != 1))continue;
                        if(c == 2 && i == 0 && j == 1 && n == 0)continue;
                        for(int m = 0; m <= 50; m++){
                            if(m * 2 > d)continue;
                            if(d == 1 && k != p)continue;
                            if(m * 2 == d && (k != 0 || p != 1))continue;
                            if(d != 1 && m * 2 == (d - 1) && (k != 0 && p != 1))continue;
                            if(d == 2 && k == 0 && p == 1 && m == 0)continue;
                            ar[0][0] = i; ar[0][1] = j; ar[0][2] = n;
                            ar[1][0] = k; ar[1][1] = p; ar[1][2] = m;
                            for(int l = 3; l <= a; l++){
                                ar[2][0] = ar[0][0]; ar[2][1] = ar[1][1];
                                ar[2][2] = ar[0][2] + ar[1][2];
                                if(ar[0][1] == 0 && ar[1][0] == 1)ar[2][2]++;
                                if(ar[2][2] > b)break;
                                REP(tmp, 3){
                                    ar[0][tmp] = ar[1][tmp];
                                    ar[1][tmp] = ar[2][tmp];
                                }
                            }
                            if(ar[2][2] == b){

                                if(i == 0)cout << "A";
                                else if(i == 1)cout << "C";
                                else cout << "B";
                                int fl = 0;
                                if(i == 0 && n > 0){
                                    cout << "C";
                                    REP(tmp, n - 1)cout << "AC";
                                    for(int tmp = n * 2; tmp < c - 1; tmp++)cout << "B";
                                }
                                else{
                                    fl++;
                                    REP(tmp, n)cout << "AC";
                                    for(int tmp = n * 2 + 1; tmp < c - 1; tmp++)cout << "B";
                                }
                                if(c != 1 && j == 0)cout << "A";
                                else if(c != 1 && j == 2)cout << "B";
                                else if(c != 1 && n * 2 != c - fl && j == 1)cout << "C";
                                cout << endl;
                                if(k == 0)cout << "A";
                                else if(k == 1)cout << "C";
                                else cout << "B";
                                fl = 0;
                                if(k == 0 && m > 0){
                                    cout << "C";
                                    REP(tmp, m - 1)cout << "AC";
                                    for(int tmp = m * 2; tmp < d - 1; tmp++)cout << "B";
                                }
                                else{
                                    fl++;
                                    REP(tmp, m)cout << "AC";
                                    for(int tmp = m * 2 + 1; tmp < d - 1; tmp++)cout << "B";
                                }
                                if(d != 1 && p == 0)cout << "A";
                                else if(d != 1 && p == 2)cout << "B";
                                else if(d != 1 && m * 2 != d - fl && p == 1)cout << "C";
                                cout << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Happy new year!" << endl;
}