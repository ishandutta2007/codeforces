#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int LOG = 18;
int a[N];
int b[N];
int low[LOG][N];
ll pre[N];
ll suff[N];
int ln[N];

int f(int li, int ri){
    int og = ln[ri - li + 1];
    return max(low[og][li], low[og][ri - (1 << og) + 1]);
}

ll gain(int li, int ri){
    if(li > ri) return 0ll;
    ll gr = ri*1ll*(ri+1)/2ll;
    ll gl = li*1ll*(li-1)/2ll;
    return gr-gl;
}

struct ele{
    int v;
    int idx;
    ll cum;
};

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        a[i]=i-a[i]+1;
        a[i]=max(a[i],1);
        b[i]=a[i];
        low[0][i]=b[i];
        a[i]=max(a[i], a[i-1]);
        pre[i]=(i-a[i]+1)+pre[i-1];
    }
    vector<ele> en;
    ll total = 0ll;
    int nah;
    ll gog;
    for(int i = n; i >= 1; i -- ){
        while(!en.empty() && b[i] >= en.back().v){
            total -= en.back().cum;
            en.pop_back();
        }
        nah = n + 1;
        if(!en.empty()) nah = en.back().idx;
        gog = gain(i + 1, nah) - (nah - i) * 1ll * b[i];
        total += gog;
        en.push_back({b[i], i, gog});
        suff[i]=total;
    }
    for(int i = 1; i <= n; i ++ ){
        ln[i]=ln[i-1];
        while((1 << (ln[i] + 1)) <= i) ln[i] ++ ;
    }
    for(int lg = 1; lg < LOG; lg ++ ){
        for(int i = 1; i <= n; i ++ ){
            if(i + (1 << lg) - 1 <= n){
                low[lg][i] = max(low[lg-1][i],low[lg-1][i + (1 << (lg - 1))]);
            }
        }
    }
    int q;
    cin >> q;
    int pi, xi;
    ll res = 0ll;
    int go;
    int nex;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> pi >> xi;
        xi=max(1, pi-xi+1);
        xi=max(a[pi-1],xi);
        res = pre[pi-1];
        go = pi;
        for(int lg = LOG - 1; lg >= 0 ;lg -- ){
            if(go + (1 << lg) <= n){
                nex = go + (1 << lg);
                if(f(pi + 1, nex) < xi){
                    go=nex;
                }
            }
        }
        res += gain(pi+1,go+1)-(go-pi+1)*1ll*xi;
        res += suff[go+1];
        cout << res << "\n";
    }
    return 0;
}