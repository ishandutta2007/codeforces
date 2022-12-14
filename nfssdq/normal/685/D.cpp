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


map < int, int > mx, my;
vector < int > vc[100001];
pair < int, int > pp[100001];
int id[2][100011], cnt[100011];
LL res[100001];

int ar[301][301][601];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 1; i <= 300; i++){
        for(int j = 1; j <= 300; j++){
            for(int k = 1; k <= i; k++){
                ar[i][j][j+k]++;
                ar[i][j][k]--;
            }
            for(int k = 599; k >= 1; k--) ar[i][j][k] += ar[i][j][k+1];
        }
    }

    int n, k; cin >> n >> k;
    FOR(i, 1, n+1){
        cin >> pp[i].xx >> pp[i].yy;
        mx[pp[i].xx] = 1;
        my[pp[i].yy] = 1;
    }
    int cx = 0, cy = 0;
    for(auto &v: mx) { v.yy = ++cx; id[0][cx] = v.xx; }
    for(auto &v: my) { v.yy = ++cy; id[1][cy] = v.xx; }

    FOR(i, 1, n+1){
        vc[mx[pp[i].xx]].pb(pp[i].yy);
    }

    id[0][0] = id[1][0] = -mod - 500;
    id[0][cx+1] = mod + 500;
    id[1][cy+1] = mod + 500;

    for(int i = 1; i <= cx; i++){
        for(int j = i; j <= cx; j++){
            if(abs(id[0][i] - id[0][j])+1 > k) break;

            int sz = k - (abs(id[0][i] - id[0][j])+1) + 2;
//            if(sz < 0) continue;
//            cout << i << " " << j << " " << sz << endl;
            LL mul = ar[min(k, id[0][i]-id[0][i-1])][min(k, id[0][j+1] - id[0][j])][sz];
            if(mul == 0) continue;

            int cc = 0;
            cnt[cc++] = -mod - 500;
            for(int l = i; l <= j; l++){
                for(int t = 0; t < vc[l].size(); t++){
                    cnt[cc++] = vc[l][t];
                }
            }
            cnt[cc++] = mod + 500;
            sort(cnt, cnt + cc);


            int rgt = 1;
            for(int l = 1; l < cc - 1; l++){
                if(cnt[l] == cnt[l-1]) continue;
                while(rgt < cc - 1){
                    if(cnt[rgt] == cnt[rgt+1]) {
                        rgt++;
                        continue;
                    }
                    if(rgt < l){
                        rgt++;
                        continue;
                    }

                    int sz2 = k - (cnt[rgt] - cnt[l] + 1) + 2;
//                    if(sz2 < 0) continue;
                    LL mul2 = ar[min(k, cnt[l] - cnt[l-1])][min(k, cnt[rgt+1] - cnt[rgt])][sz2];
                    res[rgt-l+1] += mul * mul2;

                    if(cnt[rgt+1] - cnt[l] + 1 > k) break;

//                    cout << i << " " << j << " " << cnt[l] << " " << cnt[rgt] << " " << rgt - l + 1 << " " << mul << " " << mul2 << endl;
                    rgt++;
                }
            }
        }
    }
    FOR(i, 1, n+1) cout << res[i] << " ";
    cout << endl;
}