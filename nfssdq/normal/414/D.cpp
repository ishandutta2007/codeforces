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

int ar[100001];
vector < int > vc[100001];
void dfs(int c, int p, int d){
    ar[d]++;
    REP(i, vc[c].size()){
        if(vc[c][i] == p)continue;
        dfs(vc[c][i], c, d + 1);
    }
}
int k, p;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b = 0,c,d,e = 0,f = 0,g,x,y,z;
    cin >> a >> k >> p;
    REP(i, a - 1) {
        cin >> d >> e;
        vc[d].pb(e);
        vc[e].pb(d);
    }
    if(k == 0 || p == 0){
        cout << 0 << endl;
        return 0;
    }
    dfs(1, 0, 0);
    deque < int > dq;
    for(int i = 1; i <= a - 1; i++){
        b += dq.size();
        while(b > p){
            c = dq.front();
            dq.pop_front();
            b -= (i - c);
        }
        for(int j = 1; j <= ar[i]; j++){
            if(dq.size() == k){
                c = dq.front();
                dq.pop_front();
                b -= (i - c);
            }
            dq.push_back(i);
        }
        f = max(f, (LL)dq.size());
    }
    cout << f << endl;
}