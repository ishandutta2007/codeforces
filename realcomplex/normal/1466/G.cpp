#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 10;
const int S = (int)1e6 + 10;
const int MOD = (int)1e9 + 7;
const int AL = 26;
char t[N];
int sum[AL][N];
int cnt[AL][N];
int pwr[N];

int powr(int n, int k){
    if(k == 0) return 1;
    int p = powr(n,k/2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1)
        p = (p * 1ll * n) % MOD;
    return p;
}

void add(int &a, int b){
    a += b;
    a %= MOD;
}

int match(string a, string b){
    string sha = a + '#' + b;
    int m = sha.size();
    vector<int> p(m);
    p[0]=0;
    int c;
    int yt = 0;
    for(int i = 1; i < m ; i ++ ){
        c = p[i-1];
        while(c > 0 && sha[i] != sha[c]){
            c = p[c - 1];
        }
        if(sha[i]==sha[c]) c ++ ;
        p[i]=c;
        if(p[i] == a.size()) yt ++ ;
    }
    return yt;
}

int main(){
    fastIO;
    pwr[0]=1;
    for(int i = 1; i < N;i ++ ){
        pwr[i]=(pwr[i-1]*2ll)%MOD;
    }
    int n, q;
    cin >> n >> q;
    vector<string> mx(1);
    cin >> mx[0];
    string cur;
    for(int i = 1; i <= n; i ++ ){
        cin >> t[i];
        if(mx.back().size() >= S) continue;
        cur = mx[i - 1];
        cur.push_back(t[i]);
        cur += mx[i - 1];
        mx.push_back(cur);
    }
    int id;
    int len;
    for(int i = 1; i <= n; i ++ ){
        id = t[i] - 'a';
        cnt[id][i]=1;
        sum[id][i]=pwr[n-i];
        for(int j = 0 ; j < AL; j ++ ){
            cnt[j][i] += cnt[j][i-1];
            sum[j][i] = (sum[j][i] + sum[j][i-1]) % MOD;
        }
    }
    int k;
    string f;
    int l, r;
    int mid;
    int sol = 0;
    string chk,nw;
    int cc;
    for(int id = 1; id <= q; id ++ ){
        cin >> k >> f;
        l = 0, r = mx.size();
        while(l < r){
            mid = (l + r) / 2;
            if(mx[mid].size() >= f.size())
                r=mid;
            else
                l=mid+1;
        }
        if(l>k){
            cout << 0 << "\n";
            continue;
        }
        sol = 0;
        add(sol,(pwr[n-l]*1ll*match(f,mx[l]))%MOD);
        chk.clear();
        len = f.size() - 1;
        for(int j = 0 ; j < len; j ++ ){
            chk.push_back(mx[l][mx[l].size() - len + j]);
        }
        chk.push_back('#');
        for(int j = 0 ; j < len ;j ++ ){
            chk.push_back(mx[l][j]);
        }
        for(int i = 0 ; i < AL ; i ++ ){
            cc = (sum[i][k]-sum[i][l]+MOD)%MOD;
            if(cc > 0){
                chk[len]=char(i+'a');
                add(sol,(cc*1ll*match(f,chk))%MOD);
            }
        }
        sol = (sol * 1ll * powr(pwr[n-k],MOD-2))%MOD;
        cout << sol << "\n";
    }
    return 0;
}