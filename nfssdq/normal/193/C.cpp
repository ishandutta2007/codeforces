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

//#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>
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

int s[10],loc[10],row,col;

double A[10][10];   ///a is a [row][col+1] matrix
#define eps 1e-9
void gauss()
{
    int x,y;
    for(x=0,y=0;x<row && y<col;y++)
    {
        int p=x;    ///index of the maximum absolute value in this column
        FOR(i,x+1,row) if(fabs(A[i][y])>fabs(A[p][y])+eps) p=i;

        if(fabs(A[p][y])<eps) continue;    ///no non-zero elements found in this column

        if(p!=x) FOR(j,y,col+1) swap(A[p][j],A[x][j]);    ///swap pth and xth row

        loc[y]=x;

        FOR(i,0,row)  ///convert to row echelon form
        {
            if(i==x || fabs(A[i][y])<eps) continue;  ///current row or value is already zero

            double tmp=A[i][y]/A[x][y]; ///store in temporary, use for real values
            FOR(j,y,col + 1) A[i][j] -= A[x][j]*tmp;
        }

        x++;
    }

    FOR(j,0,col)
    {
        if(loc[j]==-1) continue;
        A[loc[j]][col]/=A[loc[j]][j];   ///calculate value of jth dependent variable
        A[loc[j]][j]/=A[loc[j]][j];
    }

    return;
}
int init[6][7], tmp[7], res[8], fin[8];
int check(int x0){
    int val[7] = {0};
    FOR(i, 1, 7){
        REP(j, 6){
            val[j] += init[j][i] * res[i - 1];
        }
    }
    REP(j, 6){
        val[j] += init[j][0] * x0;
    }
    REP(i, 6) if(val[i] != tmp[i]) return 0;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g=0,h = 0,x,y,z = 0;
    FOR(i, 1, 8){
        b = 0;
        REP(j, 4){
            for(int k = j + 1; k < 4; k++){
                b++;
                if((i & 1<<j) && (i & 1<<k)) continue;
                else if((i & 1<<j) == 0 && (i & 1<<k) == 0) continue;
                else init[b - 1][d] = 1;
            }
        }
        d++;
    }
    REP(i, 6) cin >> tmp[i];
    REP(i, 6) g = max(g, tmp[i]*1ll);
    h = g * 1000;
    for(int i = 0; i <= g; i++){
        row = 6; col = 6; set0(A);
        for(int j = 0; j < 6; j++) {
            for(int k = 1; k <= 6; k++) A[j][k - 1] = init[j][k];
        }
        f = 0;
        for(int j = 0; j < 6; j++){
            if(tmp[j] < init[j][0]*i){
                f = 1;
                break;
            }
            A[j][6] = tmp[j] - init[j][0]*i;
        }
        if(f) continue;
        gauss();
//        REP(i, 6) {
//            REP(j, 7) cout << A[i][j] << " ";
//            cout << endl;
//        }
        for(int j = 0; j < 6; j++){
            double p = A[j][col];
            if(p < -eps){
                f = 1;
                break;
            }
            double q = p + 1e-7 - floor(p + 1e7);
            if(q > 1e-3){
                f = 1;
                break;
            }
            res[j] = (int)(p + 1e-7);
        }
        if(f) continue;
        f = i;
        REP(j, 6) f += res[j];
        if(f < h && check(i)){
            h = f;
            FOR(j, 1, 7) fin[j] = res[j - 1];
            fin[0] = i;
        }
    }
    if(h > 100*g)cout << -1 << endl;
    else {
        cout << h << endl;
        string ret[4];
        REP(i, 7){
            REP(j, fin[i]){
                REP(k, 4){
                    if((i+1) & 1<<k) ret[k] += "a";
                    else ret[k] += "b";
                }
            }
        }
        REP(i, 4) cout << ret[i] << endl;
    }
}