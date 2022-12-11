#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 10;
const int MOD = (int)1e9 + 7;

bool is_pr(int x){
    for(int j = 2; j * j <= x; j ++ )
        if(x % j == 0) return true;
    return false;
}

int gen_mod(){
    int mod = ((int)rng() % (int)1e9) + 1249142915;
    while(is_pr(mod)) mod ++ ;
    return mod;
}

const int HMOD = (int)1e9 + 9;
const int BASE = 27;

int powr(int n, int k){
    if(k == 0)
        return 1;
    int p = powr(n,k/2);
    p = (p * 1ll * p) % HMOD;
    if(k % 2 == 1)
        p = (p * 1ll * n) % HMOD;
    return p;
}

const int INV = powr(BASE,HMOD-2);

const int L = (int)1e6 + 10;
int pwr[L];
vector<int> pf[N];
vector<int> dp[N];
string st[N];

int calc(int i, int cut, int len){
    if(len <= cut)
        return pf[i][len-1];
    int h1 = 0;
    if(cut > 0) h1 = pf[i][cut-1];
    int h2 = (pf[i][len]-pf[i][cut]+HMOD)%HMOD;
    h2 = (h2 * 1ll * INV) % HMOD;
    return (h1 + h2) % HMOD;
}

char get(int i1, int cut, int idx /* 0 - base */ ){
    if(idx < cut){
        return st[i1][idx];
    }
    idx  ++ ;
    if(idx < st[i1].size()){
        return st[i1][idx];
    }
    else{
        return '#';
    }
}

int comp(int i1, int c1, int i2, int c2){
    int l1 = pf[i1].size();
    if(c1 < l1)
        l1 -- ;
    int l2 = pf[i2].size();
    if(c2 < l2)
        l2 -- ;
    int cp = 0;
    int nx;
    for(int lg = 20 ; lg >= 0 ; lg -- ){
        nx = cp + (1 << lg);
        if(nx > l1 || nx > l2) continue;
        if(calc(i1,c1,nx) == calc(i2,c2,nx))
            cp=nx;
    }
    char f1 = get(i1,c1,cp);
    char f2 = get(i2,c2,cp);
    if(f1 == '#')
        return true;
    if(f2 == '#')
        return false;
    return f1 <= f2;
}

int main(){
    fastIO;
    pwr[0] = 1ll;
    for(int i = 1; i < L; i ++ )
        pwr[i] = (pwr[i - 1] * 1ll * BASE) % HMOD;
    int n;
    cin >> n;
    vector<int> oo[n];
    int k;
    ll sum = 0;
    ll pp = 0;
    int sol = 0, p = 0;
    for(int i = 0 ; i < n; i ++ ){
        cin >> st[i];
        k = st[i].size();
        pf[i].resize(k);
        sum = 0;
        pp = 1;
        for(int j = 0 ; j < k ; j ++ ){
            sum = (sum + ((st[i][j] - 'a' + 1) * 1ll * pp) % HMOD) % HMOD;
            pp = (pp * 1ll * BASE) % HMOD;
            pf[i][j]=sum;
        }
        vector<int> ord(st[i].size());
        int pa = 0, pb = st[i].size() - 1;
        int nx = 0;
        for(int j = 0 ; j < st[i].size(); j ++ ){
            while(nx < st[i].size()){
                if(st[i][nx] == st[i][j])
                    nx ++ ;
                else
                    break;
            }
            if(nx == st[i].size())
                ord[pa++] = j;
            else{
                if(st[i][j] < st[i][nx]){
                    ord[pb--] = j;
                }
                else{
                    ord[pa++] = j;
                }
            }
        }

        for(auto x : ord){
            oo[i].push_back(x);
            if(x == (int)st[i].size() - 1) oo[i].push_back(st[i].size());
        }
        if(i == 0){
            dp[i].resize(oo[i].size(), 1);
        }
        else{
            dp[i].resize(oo[i].size());
            sol = 0, p = 0;
            for(int j = 0 ; j < oo[i].size(); j ++ ){
                while(p < oo[i-1].size() && comp(i-1,oo[i-1][p],i,oo[i][j])){
                    sol += dp[i-1][p];
                    sol %= MOD;
                    p ++ ;
                }
                dp[i][j] = sol;
            }

        }
    }
    int outp = 0;
    for(auto x : dp[n-1])
        outp = (outp + x) % MOD;
    cout << outp << "\n";
    return 0;
}