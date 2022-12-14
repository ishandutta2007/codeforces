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

int trie[810001][26];
int cnt[2][810001], SZ;
vector < int > ep[2][900001];
char S[800001];
void insert(int id, int idx, int f, char *s){
    cnt[f][idx]++;
    if(s[0] == '\0'){
        ep[f][idx].pb(id);
        return;
    }
    int v = s[0] - 'a';
    if(trie[idx][v] == -1){
        SZ++;
        trie[idx][v] = SZ;
    }
    insert(id, trie[idx][v], f, s + 1);
}

int ar[100001];
LL res = 0;
void query(int id){
    if(id == -1) return;
    res += (LL)min(cnt[0][id], cnt[1][id]);
    REP(i, 26){
        query(trie[id][i]);
    }
    {
        int mx = -1, sz = ep[0][id].size();
        REP(i, 26){
            int c = trie[id][i];
            if(c == -1) continue;
            if(ep[0][c].size() > sz){
                sz = ep[0][c].size();
                mx = c;
            }
        }
        if(mx != -1){
            swap(ep[0][id], ep[0][mx]);
        }
        REP(i, 26){
            int c = trie[id][i];
            if(c == -1) continue;
            REP(j, ep[0][c].size()){
                ep[0][id].pb(ep[0][c][j]);
            }
            ep[0][c].clear();
//            ep[0][c].shrink_to_fit();
        }
    }

    {
        int mx = -1, sz = ep[1][id].size();
        REP(i, 26){
            int c = trie[id][i];
            if(c == -1) continue;
            if(ep[1][c].size() > sz){
                sz = ep[1][c].size();
                mx = c;
            }
        }
        if(mx != -1){
            swap(ep[1][id], ep[1][mx]);
        }
        REP(i, 26){
            int c = trie[id][i];
            if(c == -1) continue;
            REP(j, ep[1][c].size()){
                ep[1][id].pb(ep[1][c][j]);
            }
            ep[1][c].clear();
//            ep[1][c].shrink_to_fit();
        }
    }

    {
        int sz = min(ep[0][id].size(), ep[1][id].size());
        int p = ep[1][id].size() - 1, q = sz;
        for(int i = ep[0][id].size() - 1; i >= 0; i--){
            if(sz == 0) break;
            ar[ep[0][id][i]] = ep[1][id][p];
            p--; sz--;
        }
        REP(i, q){
            ep[0][id].pop_back();
            ep[1][id].pop_back();
        }
//        ep[0][id].shrink_to_fit();
//        ep[1][id].shrink_to_fit();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    memset(trie, -1, sizeof trie);
    int len0 = 0, len1 = 0;
    FOR(i, 1, n + 1){
        cin >> S;
        len0 = strlen(S);
        insert(i, 0, 0, S);
    }
    FOR(i, 1, n + 1){
        cin >> S;
        len1 = strlen(S);
        insert(i, 0, 1, S);
    }
    query(0);
    cout << res-n << endl;
    FOR(i, 1, n + 1) cout << i << " " << ar[i] << endl;
}