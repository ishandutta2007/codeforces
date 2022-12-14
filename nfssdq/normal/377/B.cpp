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



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

#define pii pair < int, int >

LL A[100001], B[100001], C[100001], F[100001], n, m, s;
pair < LL, LL > tmp[100001];
pair < LL, pii > stud[100001];
int go(LL day){
    REP(i, m)tmp[i] = mp(A[i], i);
    sort(tmp, tmp + m);
    REP(i, n)stud[i] = mp(B[i], mp(C[i], i));
    sort(stud, stud + n);
    priority_queue < pii, vector < pii >, greater < pii > > pq;
    LL sum = 0, c = n - 1;
    for(int i = m - 1; i >= 0; i--){
        while(c >= 0){
            if(tmp[i].xx > stud[c].xx)break;
            pq.push(stud[c].yy);
            c--;
        }
        if(pq.size() == 0)return 0;
        pii pp = pq.top();
        pq.pop(); sum += pp.xx;
        for(int j = 0; j < day; j++){
            F[tmp[i].yy] = pp.yy + 1;
            i--;
            if(i < 0)break;
        }
        i++;
    }
    return sum <= s ? 1 : 0;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b = 0,c,d,f,h = 1,x,y,z;
    cin >> n >> m >> s;
    REP(i, m)cin >> A[i];
    REP(i, n)cin >> B[i];
    REP(i, n)cin >> C[i];
    LL lo = 1, hi = m + 100000, mid = (lo + hi) / 2;
    while(lo < mid){
        if(go(mid))hi = mid;
        else lo = mid + 1;
        mid = (lo + hi) / 2;
    }
    if(go(mid) == 0)mid++;
    go(mid);
    if(mid <= m){
        cout << "YES" << endl;
        REP(i, m)cout << F[i] << " ";
    }
    else cout << "NO" << endl;
}