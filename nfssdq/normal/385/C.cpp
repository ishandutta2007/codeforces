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

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


bool isp[10000001];
int sum[10000001];
int cnt[10000001];
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a;
    REP(i, a){
        cin >> b;
        cnt[b]++;
    }
    FOR(i, 2, 10000001){
        if(isp[i] == 0){
            sum[i] = cnt[i];
            for(int j = i * 2; j <= 10000000; j += i){
                isp[j] = 1;
                sum[i] += cnt[j];
            }
        }
    }
    FOR(i, 2, 10000001)sum[i] += sum[i - 1];
    cin >> a;
    REP(i, a){
        cin >> b >> c;
        if(b > 10000000){
            cout << 0 << endl;
            continue;
        }
        c = min(c, 10000000);
        cout << sum[c] - sum[b - 1] << endl;
    }
}