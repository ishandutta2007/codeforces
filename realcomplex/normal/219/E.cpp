#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 9;
set<pii> len, pos;
int n, m;

void add_seg(int L, int R){
    if(L>R)
        return;
    int sz = R-L+1;
    pos.insert(mp(L,sz));
    if(L!=1 && R!=n)
        sz = (sz + 1) / 2;
    len.insert(mp(sz,L));
}

void rem_seg(int L, int R){
    if(L>R)
        return;
    int sz = R-L+1;
    pos.erase(mp(L,sz));
    if(L!=1 && R!=n)
        sz = (sz + 1) / 2;
    len.erase(mp(sz,L));
}
int loc[N];

void add(int x){
    auto it = len.end();
    -- it;
    int opt = it->fi;
    it = len.lower_bound(mp(opt,-1));
    auto segt = pos.lower_bound(mp(it->se, -1));
    int L = segt->fi;
    int R = L + (segt->se) - 1;
    rem_seg(L,R);
    int M = (L+R)/2;
    if(L==1) M=1;
    else if(R==n) M = R;
    cout << M << "\n";
    loc[x] = M;
    add_seg(L,M-1);
    add_seg(M+1,R);
}

void rem(int x){
    int pp = loc[x];
    loc[x] = 0;
    int L = pp, R = pp;
    auto v2 = pos.lower_bound(mp(pp+1, -1));
    if(v2 != pos.end() && v2->fi == pp + 1){
        R = (v2->fi) + (v2->se) - 1;

        rem_seg(v2->fi, (v2->fi) + (v2->se) - 1);
    }
    v2 = pos.lower_bound(mp(pp+1, -1));
    if(v2 != pos.begin()){
        -- v2;
        if((v2->fi) + (v2->se) - 1 == pp - 1){
            L = v2->fi;
            rem_seg(v2->fi, pp - 1);
        }
    }
    add_seg(L,R);
}

int main(){
    fastIO;
    cin >> n >> m;
    add_seg(1,n);
    int typ;
    int id;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> typ >> id;
        if(typ==1) add(id);
        else rem(id);
    }
    return 0;
}