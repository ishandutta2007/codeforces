#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int K = 2150;

int A[N];

struct Sha{
    int idx;
    int ai;
    int bi;
    // set idx from ai to bi
};

struct Query{
    int upd;
    int lef;
    int rig;
    int kval;
    int id;
    bool operator< (const Query &qq) const {
        if(upd/K == qq.upd/K){
            if(lef / K == qq.lef / K)
                return rig < qq.rig;
            else
                return lef / K < qq.lef / K;
        }
        return upd/K < qq.upd/K;
    }
};

int outp[N];

int cnt[N];
int cc[N];

vector<int> que; // i think it works
bool inq[N];

void add(int v){
    cc[cnt[v]] -- ;
    cnt[v]++;
    cc[cnt[v]] ++ ;
    if(cc[cnt[v]] == 1 && !inq[cnt[v]]){
        inq[cnt[v]]=true;
        que.push_back(cnt[v]);
    }
}

void del(int v){
    cc[cnt[v]] -- ;
    cnt[v] -- ;
    cc[cnt[v]] ++ ;
    if(cc[cnt[v]] == 1 && !inq[cnt[v]]){
        inq[cnt[v]]=true;
        que.push_back(cnt[v]);
    }
}

int uni[N];


int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        uni[i] = A[i];
    }
    vector<Sha> ars;
    vector<Query> ans;
    int typ;
    int lef, rig;
    int vl;
    for(int i = 1; i <= q; i ++ ){
        cin >> typ;
        if(typ == 1){
            cin >> lef >> rig >> vl;
            ans.push_back({(int)ars.size(), lef, rig, vl, (int)ans.size()});
        }
        else{
            cin >> lef >> vl;
            ars.push_back({lef, A[lef], vl});
            A[lef] = vl;
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 1; i <= n; i ++ ){
        A[i] = uni[i];
    }
    int li = 1, ri = 0;
    int up = 0;
    int sol = 0;
    int cum = 0, pi = 0;
    for(int qr = 0; qr < ans.size() ; qr ++ ){
        while(up < ans[qr].upd){
            if(ars[up].idx >= li && ars[up].idx <= ri){
                del(ars[up].ai);
                add(ars[up].bi);
            }
            A[ars[up].idx] = ars[up].bi;
            up ++ ;
        }
        while(up > ans[qr].upd){
            up -- ;
            if(ars[up].idx >= li && ars[up].idx <= ri){
                del(ars[up].bi);
                add(ars[up].ai);
            }
            A[ars[up].idx] = ars[up].ai;
        }
        while(li > ans[qr].lef){
            li--;
            add(A[li]);
        }
        while(ri < ans[qr].rig){
            ri ++ ;
            add(A[ri]);
        }
        while(li < ans[qr].lef){
            del(A[li]);
            li++;
        }
        while(ri > ans[qr].rig){
            del(A[ri]);
            ri--;
        }

        vector<int> nw;
        for(auto r : que){
            if(cc[r] == 0){
                inq[r]=false;
            }
            else{
                nw.push_back(r);
            }
        }
        que = nw;
        vector<pii> ord;
        for(auto q : que){
            ord.push_back(mp(q, cc[q]));
        }
        sort(ord.begin(), ord.end());
        cum = 0;
        pi = 0;
        sol = (int)1e9;
        for(int i = 0 ; i < ord.size(); i ++ ){
            cum += ord[i].se;
            if(cum >= ans[qr].kval){
                while(cum - ord[pi].se >= ans[qr].kval){
                    cum -= ord[pi].se;
                    pi ++ ;
                }
                sol = min(sol, ord[i].fi-ord[pi].fi);
            }
        }
        if(sol == (int)1e9) sol = -1;
        outp[ans[qr].id] = sol;

    }
    for(int i = 0 ; i < ans.size(); i ++ ){
        cout << outp[i] << "\n";
    }
    return 0;
}