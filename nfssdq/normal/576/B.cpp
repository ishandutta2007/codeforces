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

vector < int > vc[100001];
int vis[100001], ar[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    FOR(i, 1, n+1) cin >> ar[i];
    int cnt = 0, mn = n+1, id = 0;
    FOR(i, 1, n+1){
        if(vis[i]) continue;
        int p = ar[i];
        while(p != i){
            vis[p] = 1;
            vc[cnt].pb(p);
            p = ar[p];
        }
        vis[p] = 1;
        vc[cnt].pb(p);
        if(vc[cnt].size() < mn){
            mn = vc[cnt].size();
            id = cnt;
        }
        cnt++;
    }
    if(mn > 2){
        cout << "NO" << endl;
        return 0;
    }
    else if(mn == 2){
        int fl  = 0;
        REP(i, cnt){
            if(vc[i].size() % 2 != 0) fl = 1;
        }
        if(fl){
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        REP(i, cnt){
            if(i == id){
                cout << vc[i][0] << " " << vc[i][1] << endl;
            } else {
                REP(j, vc[i].size()){
                    int p = j % 2;
                    cout << vc[id][p] << " " << vc[i][j] << endl;
                }
            }
        }
        return 0;
    }else {
        cout << "YES" << endl;
        REP(i, cnt){
            if(i != id){
                REP(j, vc[i].size()){
                    cout << vc[id][0] << " " << vc[i][j] << endl;
                }
            }
        }
    }
}