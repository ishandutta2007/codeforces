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


int N;
LL mul_res[151][3];
void multiply(LL a[][3], LL b[][3]){
    set0(mul_res);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < 3; k++){
                LL v = a[i][k] & b[j][k];
                if(v) mul_res[i][j/60] |= 1ll<<(j % 60);
            }
        }
    }
}

LL big_res[151][3];
LL init[151][3], tmp[151][3];
void matrix_expo(LL n){
    if(n == 0){
        set0(big_res);
        REP(i, N) big_res[i][i/60] |= 1ll<<(i%60);
        return;
    }
    if(n % 2 == 0){
        matrix_expo(n / 2);
        set0(tmp);
        REP(i, N){
            REP(j, N)
                if(big_res[i][j/60] & 1ll<<(j%60))
                    tmp[j][i/60] |= 1ll<<(i%60);
        }
        multiply(big_res, tmp);
        REP(i, N){
            REP(j, 3)big_res[i][j] = mul_res[i][j];
        }
    }
    else {
        matrix_expo(n - 1);
        set0(tmp);
        REP(i, N){
            REP(j, N){
                if(init[i][j/60] & 1ll<<(j%60)){
                    tmp[j][i/60] |= 1ll<<(i%60);
                }
            }
        }
        multiply(big_res, tmp);
        REP(i, N){
            REP(j, 3)big_res[i][j] = mul_res[i][j];
        }
    }
}


pair < int, pair < int, int > > pp[151];
vector < int > vc[151];
int vis[151];
queue < int > Q;

LL fin_res[151][3];

void bfs(){
    memset(vis, -1, sizeof vis);
    REP(i, N){
        if(fin_res[0][i/60] & 1ll<<(i%60)){
            Q.push(i);
            vis[i] = 0;
//            cout << i << " ";
        }
    }
//    cout << endl;
    while(!Q.empty()){
        int c = Q.front();
        Q.pop();

        REP(i, vc[c].size()){
            if(vis[ vc[c][i] ] == -1){
                vis[vc[c][i]] = vis[c] + 1;
                Q.push(vc[c][i]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m; cin >> N >> m;
    REP(i, m) {
        cin >> pp[i].yy.xx >> pp[i].yy.yy >> pp[i].xx;
        pp[i].yy.xx--; pp[i].yy.yy--;
    }
    sort(pp, pp + m);

    REP(i, N) fin_res[i][i/60] |= 1ll<<(i%60);

    int last = 0;
    REP(i, m){
        if(i < m-1 && pp[i+1].xx == pp[i].xx) continue;

        matrix_expo(pp[i].xx - last);
        set0(tmp);
        REP(j, N){
            REP(k, N)
                if(big_res[j][k/60] & 1ll<<(k%60))
                    tmp[k][j/60] |= 1ll<<(j%60);
        }
        multiply(fin_res, tmp);
        REP(j, N) REP(k, 3) fin_res[j][k] = mul_res[j][k];

//        REP(j, N){
//            REP(k, N) if(fin_res[j][k/60] & 1ll<<(k%60)) cout << "1";
//            else cout << 0;
//            cout << endl;
//        }
//        cout << endl;
//        REP(j, N){
//            REP(k, N) if(big_res[j][k/60] & 1ll<<(k%60)) cout << "1";
//            else cout << 0;
//            cout << endl;
//        }
//        cout << endl;

        REP(j, N) vc[j].clear();
        for(int j = 0; j <= i; j++){
            init[pp[j].yy.xx][pp[j].yy.yy/60] |= 1ll<<(pp[j].yy.yy%60);
            vc[pp[j].yy.xx].pb(pp[j].yy.yy);
        }

//        cout << pp[i].xx << endl;
        bfs();
        if(vis[N-1] != -1) {
            cout << pp[i].xx + vis[N-1] << endl;
            return 0;
        }
        last = pp[i].xx;
    }

    cout << "Impossible" << endl;
}