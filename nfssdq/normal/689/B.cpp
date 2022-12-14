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
#include<unordered_set>

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


queue < int > Q;
int ar[200001], dis[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        dis[i] = mod;
    }
    dis[1] = 0;
    Q.push(1);
    while(!Q.empty()){
        int c = Q.front(); Q.pop();
        if(c+1 <= n && dis[c+1] > 1 + dis[c]){
            Q.push(c+1);
            dis[c+1] = 1 + dis[c];
        }
        if(c-1 >= 1 && dis[c-1] > 1 + dis[c]){
            Q.push(c-1);
            dis[c-1] = 1 + dis[c];
        }
        if(ar[c] <= n && dis[ar[c]] > 1 + dis[c]){
            Q.push(ar[c]);
            dis[ar[c]] = 1 + dis[c];
        }
    }
    FOR(i, 1, n+1) cout << dis[i] << " ";
    cout << endl;
}