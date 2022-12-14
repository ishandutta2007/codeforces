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

LL ar[200001], k, sum[5];

priority_queue < LL > pq[5];

void add(int id, LL v){
    pq[id].push(v);
    sum[id] += v;
    if(pq[id].size() > k){
        sum[id] -= pq[id].top();
        pq[id].pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n, b, c; cin >> n >> k >> b >> c;
    REP(i, n) {
        cin >> ar[i];
        ar[i] += mod;
    }
    sort(ar, ar + n);

    if(5*c <= b){
        LL sum = 0, res = mod * mod;
        for(int i = 0; i < k; i++) sum += ar[i];
        for(int i = k-1; i < n; i++){
            res = min(res, (ar[i]*k - sum) * c);
            sum -= ar[i-k+1];
            if(i < n-1) sum += ar[i+1];
        }
        cout << res << endl;
        return 0;
    }

    REP(i, k - 1){
        for(int j = ar[i]; j <= ar[i]+4; j++){
            add(j%5, -(j/5)*b + (j-ar[i])*c);
        }
    }

    LL res = mod * mod;
    for(int i = k-1; i < n; i++){
        for(int j = ar[i]; j <= ar[i]+4; j++){
            add(j%5, -(j/5)*b + (j-ar[i])*c);
        }
        for(int j = ar[i]; j <= ar[i]+5; j++){
            res = min(res, (j/5)*b*k + sum[j%5]);
        }
    }

    cout << res << endl;
}