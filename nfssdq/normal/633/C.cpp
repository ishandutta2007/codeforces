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

struct trie{
    int nxt[26], ep;
    trie(){
        memset(nxt, -1, sizeof nxt);
        ep = -1;
    }
};
trie tr[1200001];

int cnt = 0;
string ss[100001], original[100001];
void insert(int idx, int p, int v){
    if(v == ss[p].size()){
        tr[idx].ep = p;
        return;
    }

    int nxt = tr[idx].nxt[ss[p][v]-'a'];
    if(nxt == -1){
        tr[cnt++] = trie();
        tr[idx].nxt[ss[p][v]-'a'] = nxt = cnt-1;
    }

    insert(tr[idx].nxt[ss[p][v]-'a'], p, v+1);
}

int dp[100011], pos[100011];
string S;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n >> S;
    int m; cin >> m;

    tr[cnt++] = trie();
    REP(i, m){
        cin >> ss[i];
        original[i] = ss[i];
        reverse(ss[i].begin(), ss[i].end());
        REP(j, ss[i].size()){
            if(ss[i][j] >= 'A' && ss[i][j] <= 'Z') ss[i][j] = ss[i][j] - 'A' + 'a';
        }
        insert(0, i, 0);
    }

    dp[n] = 1;
    for(int i = n-1; i >= 0; i--){
        int st = 0;
        for(int j = i; j < n; j++){
            int p = tr[st].nxt[S[j]-'a'];
            if(p == -1) break;
            st = p;
            if(tr[st].ep >= 0 && dp[j+1]){
                dp[i] = 1;
                pos[i] = tr[st].ep;
                break;
            }
        }
    }

    int st = 0;
    while(st < n){
        cout << original[pos[st]] << " ";
        st += ss[pos[st]].size();
    }
    cout << endl;
}