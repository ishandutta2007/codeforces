#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2005;
const int M = 4005;
int cnt[M];
int l[N], r[N];

int inter(int i1, int j1, int i2, int j2){
    return max(0,min(j1,j2)-max(i1,i2)+1);
}

int main(){
    fastIO;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++ ){
        cin >> l[i] >> r[i];
    }
    int en;
    int cur;
    int cc;
    int sz;
    int la, ra;
    int el, er;
    int nx;
    int dif;
    int cum;
    int sol = 0;
    for(int st = 1; st <= n-k+1; st ++ ){
        en = st + k - 1;
        cur = 0;
        for(int t = 0; t < M; t ++ )
            cnt[t]=0;
        for(int i = 1; i <= m; i ++ ){
            cc = inter(st, en, l[i], r[i]);
            sz = min(en-st+1, r[i]-l[i]+1);
            cur += cc;
            if(sz == cc) continue;
            la = (l[i]+sz-1)-k+1;
            ra = r[i]-sz+1;
            la = max(la,1);
            el = la;
            er = ra;
            for(int lg = 13; lg >= 0 ;lg -- ){
                nx = (el-(1<<lg));
                if(nx <= 0) continue;
                if(inter(nx,nx+k-1,l[i],r[i]) > cc){
                    el = nx;
                }
            }
            for(int lg = 13; lg >= 0 ; lg -- ){
                nx = (er+(1<<lg));
                if(nx > n) continue;
                if(inter(nx,nx+k-1,l[i],r[i]) > cc){
                    er = nx;
                }
            }
            dif = inter(el,el+k-1,l[i],r[i])-cc-1;
            cnt[el]+=dif;
            cnt[el+1]-=dif;
            cnt[el]++;
            cnt[la+1]--;
            cnt[ra+1]--;
            cnt[er+2]++;
        }
        cum = 0;
        for(int i = 1; i <= n; i ++ ){
            cum += cnt[i];
            cur += cum;
            sol = max(sol, cur);
        }
    }
    cout << sol << "\n";
    return 0;
}