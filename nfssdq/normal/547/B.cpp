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

int pre[200001], sz[200001];
int Find(int x){
    if(x == pre[x]) return x;
    return pre[x] = Find(pre[x]);
}
int mx = 1;
void Union(int x, int y){
    int px = Find(x), py = Find(y);
    if(px == py) return;
    pre[px] = py;
    sz[py] += sz[px];
    mx = max(mx, sz[py]);
}
pair < int, int > pp[200001];
int ar[200001], res[200001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    FOR(i, 1, n+1){
        cin >> pp[i].xx;
        pp[i].yy = i;
        sz[i] = 1;
        pre[i] = i;
        ar[i] = 0;
    }
    sort(pp + 1, pp + n + 1);
    int last = 0;
    for(int i = n; i >= 1; i--){
        ar[pp[i].yy] = 1;
        if(pp[i].yy > 1 && ar[pp[i].yy - 1]) Union(pp[i].yy, pp[i].yy - 1);
        if(pp[i].yy < n && ar[pp[i].yy + 1]) Union(pp[i].yy, pp[i].yy + 1);
        for(int j = last + 1; j <= mx; j++) res[j] = pp[i].xx;
        last = mx;
    }
    FOR(i, 1, n+1) cout << res[i] << " ";
    cout << endl;
}