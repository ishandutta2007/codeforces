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

// up, down, right, left
LL dis[2002][2002][4];
char pp[2002][2002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    REP(i, n) cin >> pp[i];

    REP(i, n){
        REP(j, m){
            if(pp[i][j] == '#') continue;
            if(i == 0) dis[i][j][0] = 1;
            else dis[i][j][0] = dis[i - 1][j][0];
        }
    }

    for(int i = n - 1; i >= 0; i--){
        REP(j, m){
            if(pp[i][j] == '#') continue;
            if(i == n - 1) dis[i][j][1] = 1;
            else dis[i][j][1] = dis[i + 1][j][1];
        }
    }

    REP(i, m){
        REP(j, n){
            if(pp[j][i] == '#') continue;
            if(i == 0) dis[j][i][2] = 1;
            else dis[j][i][2] = dis[j][i - 1][2];
        }
    }

    for(int i = m - 1; i >= 0; i--){
        REP(j, n){
            if(pp[j][i] == '#') continue;
            if(i == m - 1) dis[j][i][3] = 1;
            else dis[j][i][3] = dis[j][i + 1][3];
        }
    }

    LL res = 0;

    for(int i = 1; i < n - 1; i++){
        int last = 0;
        LL one = 0, two = 0;
        for(int j = 1; j < m; j++){
            if(pp[i][j] == '#' || j == m - 1){

                res += (one * (one - 1)) / 2ll;
                res += (two * (two - 1)) * 2ll;
                res += two * one * 2ll;

                for(int k = last + 2; k < j; k++){
                    if(dis[i][k][0] && dis[i][k - 1][0]) res--;
                    if(dis[i][k][1] && dis[i][k - 1][1]) res--;
                }

                last = j;

                one = two = 0;
            } else {
                if(dis[i][j][0] == 1 && dis[i][j][1] == 1) two++;
                else if(dis[i][j][0] == 1 || dis[i][j][1] == 1) one++;
            }
        }
        if(dis[i][m - 1][2]) res++;
    }


    for(int j = 1; j < m-1; j++){
        int last = 0;
        LL one = 0, two = 0;
        for(int i = 1; i < n; i++){
            if(pp[i][j] == '#' || i == n - 1){

                res += (one * (one - 1)) / 2ll;
                res += (two * (two - 1)) * 2ll;
                res += two * one * 2ll;

                for(int k = last + 2; k < i; k++){
                    if(dis[k][j][2] && dis[k - 1][j][2]) res--;
                    if(dis[k][j][3] && dis[k - 1][j][3]) res--;
                }

                last = i;

                one = two = 0;
            } else {
                if(dis[i][j][2] == 1 && dis[i][j][3] == 1) two++;
                else if(dis[i][j][2] == 1 || dis[i][j][3] == 1) one++;
            }
        }
        if(dis[n - 1][j][0]) res++;
    }


    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            int vertical = dis[i][j][0] + dis[i][j][1];
            int horizontal = dis[i][j][2] + dis[i][j][3];

            res += horizontal * vertical;
        }
    }

    cout << res << endl;
}