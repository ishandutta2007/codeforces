#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair

const int N = (int)2e5 + 10;
int ans[N];

pii get(int l, int r){
    if(l == r && ans[l] != 0) return mp(ans[l], 1);
    cout << "? " << l << " " << r << endl;
    pii ret;
    cin >> ret.fi >> ret.se;
    return ret;
}

void solve(int li, int ri){
    if(li > ri) return;
    pii sol = get(li, ri);
    int p = 0;
    int q = 1;
    while(q * 2 <= sol.se)
        q *= 2;
    pii nx;
    vector<int> ind;
    for(int i = li ; i <= ri ; i ++ ){
        if(i % q == 0){
            if(ans[i] == 0){
                nx = get(i, i);
                ans[i]=nx.fi;
            }
            if(ans[i] == sol.fi){
                ind.push_back(i);
            }
        }
    }
    if(ind.size() == 2){
        pii pv = get(max(li,ind[1]-sol.se+1), ind[1]);
        int st = ind[1]-pv.se+1;
        int en = st+sol.se-1;
        for(int i = st; i <= en; i ++ ){
            ans[i] = sol.fi;
        }
        solve(li, st - 1);
        solve(en + 1, ri);
        return;
    }
    pii f1 = get(max(li,ind[0]-sol.se+1),ind[0]);
    pii f2 = get(ind[0], min(ri,ind[0]+sol.se-1));
    if(f1.fi == sol.fi){
        int gl = ind[0]-f1.se+1;
        int gr = gl+sol.se-1;
        for(int i = gl; i <= gr; i ++ ){
            ans[i] = sol.fi;
        }
        solve(li,gl-1);
        solve(gr+1,ri);
    }
    else{
        int gr = ind[0]+f2.se-1;
        int gl = gr-sol.se+1;
        for(int i = gl; i <= gr; i ++ ){
            ans[i] = sol.fi;
        }
        solve(li,gl-1);
        solve(gr+1,ri);
    }

}

int main(){
    int n;
    cin >> n;
    solve(1, n);
    cout << "! ";
    for(int i = 1; i <= n; i ++ )
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}