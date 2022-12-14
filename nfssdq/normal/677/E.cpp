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


string ss[1011];
int cnt[4][4][1501][1501], n;

int go(int i, int j, int m){
    if(i+m-1 > n || j+m-1 > n || i-m+1 < 1 || j-m+1 < 1) return 0;
    int v1 = cnt[0][0][i][j+m-1] - cnt[0][0][i][j-m];
    v1 += cnt[1][0][i+m-1][j] - cnt[1][0][i-m][j];

    int v2 = cnt[2][0][i+m-1][j-m+1] - cnt[2][0][i-m][j+m];
    v2 += cnt[3][0][i+m-1][j+m-1] - cnt[3][0][i-m][j-m];

    if(v1 == 0 || v2 == 0) return 1;
    return 0;
}

long double p2[5001], p3[5001];

bool cmp(pair<int,int> px, pair<int,int> py){
    return p2[px.xx]+p3[px.yy] < p2[py.xx]+p3[py.yy];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	FOR(i, 1, n+1) cin >> ss[i];
	FOR(i, 1, n+1){
        FOR(j, 1, n+1){
            REP(k, 4) cnt[0][k][i][j] = cnt[0][k][i][j-1];
            cnt[0][ ss[i][j-1]-'0' ][i][j]++;

            REP(k, 4) cnt[2][k][i][j] = cnt[2][k][i-1][j+1];
            cnt[2][ ss[i][j-1]-'0' ][i][j]++;

            REP(k, 4) cnt[3][k][i][j] = cnt[3][k][i-1][j-1];
            cnt[3][ ss[i][j-1]-'0' ][i][j]++;

            REP(k, 4) cnt[1][k][i][j] = cnt[1][k][i-1][j];
            cnt[1][ ss[i][j-1]-'0' ][i][j]++;
        }
	}

	p2[0] = p3[0] = 0;
	for(int i = 1; i <= 5000; i++){
        p2[i] = p2[i-1] + log(2.0);
        p3[i] = p3[i-1] + log(3.0);
	}

	pair < int, int > pp = mp(0, 0);

	int fl = 0;
	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(ss[i][j-1] == '0') continue;
            fl = 1;
            int lo = 1, hi = n, mid = (lo + hi) / 2;
            while(lo < mid){
                if(go(i, j, mid)) lo = mid;
                else hi = mid - 1;
                mid = (lo + hi) / 2;
            }
            if(go(i, j, mid+1)) mid++;

            int tmp[4];
            REP(k, 4){
                tmp[k] = 0;
                tmp[k] += cnt[0][k][i][j+mid-1] - cnt[0][k][i][j-mid];
                tmp[k] += cnt[1][k][i+mid-1][j] - cnt[1][k][i-mid][j];
            }
            tmp[ss[i][j-1]-'0']--;
            if(tmp[0] == 0){
                if(cmp(pp, mp(tmp[2], tmp[3]))) pp = mp(tmp[2], tmp[3]);
            }
            REP(k, 4){
                tmp[k] = 0;
                tmp[k] += cnt[2][k][i+mid-1][j-mid+1] - cnt[2][k][i-mid][j+mid];
                tmp[k] += cnt[3][k][i+mid-1][j+mid-1] - cnt[3][k][i-mid][j-mid];
            }
            tmp[ss[i][j-1]-'0']--;
            if(tmp[0] == 0){
                if(cmp(pp, mp(tmp[2], tmp[3]))) pp = mp(tmp[2], tmp[3]);
            }
        }
	}
	if(fl == 0){
        cout << 0 << endl;
        return 0;
	}
    LL ret = 1;
    FOR(i, 1, pp.xx+1) ret = (ret * 2ll) % mod;
    FOR(i, 1, pp.yy+1) ret = (ret * 3ll) % mod;
    cout << ret << endl;
}