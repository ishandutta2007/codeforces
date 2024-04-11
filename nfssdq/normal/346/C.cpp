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
#define linf       (1<<60)-1
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
LL vc[1000005];
LL cnt[1000005], ar[100001];
map < LL, LL > mm;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f,g,h = 0,x,y,z;
    cin >> a;
    REP(i, a){
        cin >> b;
        if(mm[b] == 0)ar[h++] = b;
        mm[b] = 1ll;
    }
    cin >> c >> d;
    a = h;
    sort(ar, ar + h);
    REP(i, a){
        b = d / ar[i];
        if(d % ar[i] != 0)b++;
        while(b * ar[i] <= c){
            vc[b*ar[i] - d] = ar[i];
            b++;
        }
    }
    if(c == d){
        cout << 0;
        return 0;
    }
    e = 0;
    REP(i, c - d + 1){
        if(e == i)cnt[++e] = 1 + cnt[i];
        f = i + vc[i] - 1;
        if(f > c - d)f = c - d;
        while(e < f){
            e++;
            cnt[e] = 1 + cnt[i];
        }
    }
    cout << cnt[c - d] << endl;
}