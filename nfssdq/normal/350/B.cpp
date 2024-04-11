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

LL nxt[100001], on[100001];
LL cnt, ar[100001], sum[100001];
void dfs(int p){
    ar[cnt++] = p;
    if(nxt[p] == 0 || on[nxt[p]] == 1 || sum[nxt[p]] > 1)return;
    dfs(nxt[p]);
}
vector < LL > pp;
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	LL a,b = 0,c,d,e = 0,f,g,h = 1,x = 0,y,z;
    cin >> a;
    FOR(i, 1, a + 1)cin >> on[i];
    FOR(i, 1, a + 1)cin >> nxt[i], sum[nxt[i]]++;
    FOR(i, 1, a + 1){
        if(on[i] == 0)continue;
        cnt = 0;
        dfs(i);
        if(cnt > pp.size()){
            pp.clear();
            for(int j = cnt - 1; j >= 0; j--)pp.pb(ar[j]);
        }
    }
    cout << pp.size() << endl;
    REP(i, pp.size())cout << pp[i] << " ";
}