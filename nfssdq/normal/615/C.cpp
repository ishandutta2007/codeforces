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

string s, t;
struct node {
    int nxt[26];
    int sf, ef;
    node(){
        memset(nxt, -1, sizeof nxt);
        sf = ef = -1;
    }
} ;
node ar[2100 * 2100];

int cc = 0;
void insert(int p, int x, int st, int f){
    ar[x].ef = p - 1;
    if(f) ar[x].ef += 2;
    ar[x].sf = st;
    if((f == 0 && p == s.size()) || (f == 1 && p == -1)){
        return;
    }

    int nv = s[p] - 'a';
    int np = p + 1;
    if(f) np -= 2;
    int nxt_id = ar[x].nxt[ nv ];
    if(nxt_id == -1){
        ar[cc] = node();
        nxt_id = cc;
        ar[x].nxt[nv] = cc;
        cc++;
    }

    insert(np, nxt_id, st, f);
}

vector < pair < int, int > > vc;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;

    ar[0] = node();
    cc++;

    REP(i, s.size()){
        insert(i, 0, i, 0);
        insert(i, 0, i, 1);
    }

    int st = 0, x = 0;
    for(int i = 0; i < t.size(); i++){
        int v = t[i] - 'a';
        if(x == 0 && ar[x].nxt[v] == -1){
            cout << -1 << endl;
            return 0;
        }

        if(ar[x].nxt[v] == -1){
            vc.pb(mp( ar[x].sf, ar[x].ef ));
            i--;
            x = 0;
            continue;
        } else {
            x = ar[x].nxt[v];
        }
    }

    vc.pb(mp( ar[x].sf, ar[x].ef));

    cout << vc.size() << endl;
    REP(i, vc.size()) cout << vc[i].xx+1 << " " << vc[i].yy+1 << endl;
}