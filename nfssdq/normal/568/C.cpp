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

vector < int > vc[500], rev[500], group[500];
stack < int > ss;
int vis[500], id[500];
void dfs(int c){
    vis[c] = 1;
    REP(i, vc[c].size()){
        if(vis[vc[c][i]] == 0) dfs(vc[c][i]);
    }
    ss.push(c);
}
void FindScc(int c, int v){
    group[v].pb(c);
    vis[c] = 1; id[c] = v;
    REP(i, rev[c].size()){
        if(vis[ rev[c][i] ] == 0) FindScc(rev[c][i], v);
    }
}

string alpha, S;
int compliment(int x){
    if(x <= 200) return x+250;
    else return x-250;
}

int check(int n){

    set0(vis);
    FOR(i, 1, 500){
        if(vis[i] == 0) dfs(i);
    }
    int cnt = 0;
    set0(vis);
    while(!ss.empty()){
        int p = ss.top();
        ss.pop();
        if(vis[p]) continue;

        FindScc(p, ++cnt);
    }

    for(int i = 1; i <= n; i++){
        if(id[i] == id[i+250]){
            return 0;
        }
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> alpha;
    int n, m; cin >> n >> m;
    REP(i, m){
        int p, q; string s1, s2;
        cin >> p >> s1 >> q >> s2;
        int invp = p, invq = q;

        if(s1 == "V") invp = p + 250;
        else p += 250;

        if(s2 == "V") invq = q + 250;
        else q += 250;

        vc[p].pb(q);
        rev[q].pb(p);

        vc[invq].pb(invp);
        rev[invp].pb(invq);

    }
    cin >> S;
    string res = "";

    for(int i = 1; i <= n; i++){
        int p = S[i-1] - 'a';
        if(alpha[p] == 'V') p = i;
        else p = i + 250;

        vc[compliment(p)].pb(p);
        rev[p].pb(compliment(p));
    }

    if(check(n)){
        cout << S << endl;
        return 0;
    }

    int pos = -1;
    for(int i = n; i >= 1; i--){
        int f1 = 0, f2 = 0;
        f1 = check(n);

        int p = S[i-1] - 'a';
        if(alpha[p] == 'V') p = i;
        else p = i + 250;

        vc[compliment(p)].pop_back();
        rev[p].pop_back();

        vc[p].pb(compliment(p));
        rev[compliment(p)].pb(p);

        f2 = check(n);

        vc[p].pop_back();
        rev[compliment(p)].pop_back();

        int p1 = -1, p2 = -1;

        p = S[i-1] - 'a';
        for(int j = p + 1; j < alpha.size(); j++){
            if(alpha[j] == alpha[p] && p1 == -1){
                p1 = j;
            }
            if(alpha[j] != alpha[p] && p2 == -1){
                p2 = j;
            }
        }
        if(alpha[p] == 'V') p = i;
        else p = i + 250;

        if(p1 == -1) f1 = 0;
        if(p2 == -1) f2 = 0;

        if(f2 == 0 && f1 == 0) continue;
        for(int j = 1; j < i; j++) res += S[j-1];
        if(f2 == 0 || (f1 && f2 && p1 < p2)){
            vc[compliment(p)].pb(p);
            rev[p].pb(compliment(p));

            res += p1 + 'a';
        } else {
            vc[p].pb(compliment(p));
            rev[compliment(p)].pb(p);

            res += p2 + 'a';
        }

        for(int j = i + 1; j <= n; j++){
            int p = j;
            if(alpha[0] == 'C') p += 250;

            vc[compliment(p)].pb(p);
            rev[p].pb(compliment(p));

            if(check(n)){
                res += 'a';
                continue;
            }

            vc[compliment(p)].pop_back();
            rev[p].pop_back();

            vc[p].pb(compliment(p));
            rev[compliment(p)].pb(p);

            if(check(n) == 0){
                cout << -1 << endl;
                return 0;
            }

            p1 = -1;
            for(int k = 1; k < alpha.size(); k++){
                if(alpha[k] != alpha[0]){
                    p1 = k;
                    break;
                }
            }

            if(p1 == -1){
                cout << -1 << endl;
                return 0;
            }
            res += p1 + 'a';
        }
        cout << res << endl;
        return 0;

    }
    cout << -1 << endl;
}