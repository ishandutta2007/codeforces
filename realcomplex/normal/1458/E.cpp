#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;
const int INF = (int)1e9 + 9;
int x[N], y[N];

struct cross{
    int val;
    int li;
    int ri;
};

set<pii> segm[N];

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    set<pii> pp;
    vector<pii> xx, yy;
    pp.insert(mp(0,0));
    for(int i = 0; i < n; i ++ ){
        cin >> x[i] >> y[i];
        xx.push_back(mp(x[i],y[i]));
        yy.push_back(mp(y[i],x[i]));
        pp.insert(mp(x[i],y[i]));
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    xx.push_back(mp(INF,INF));
    yy.push_back(mp(INF,INF));
    int nx = 0, ny = 0;
    vector<cross> sha;
    int ci = 0, cj = 0;
    int di, dj;
    int delta;
    while(1){
        if(ci == INF || cj == INF) break;
        if(pp.count(mp(ci,cj))){
            ci ++ ;
            cj ++ ;
            continue;
        }
        while(xx[nx].fi < ci){
            nx ++ ;
        }
        if(xx[nx].fi == ci && xx[nx].se < cj){
            ci ++;
            continue;
        }
        while(yy[ny].fi < cj){
            ny ++ ;
        }
        if(yy[ny].fi == cj && yy[ny].se < ci){
            cj ++ ;
            continue;
        }
        while(xx[nx].fi == ci) nx ++ ;
        while(yy[ny].fi == cj) ny ++ ;
        di = xx[nx].fi-ci;
        dj = yy[ny].fi-cj;
        delta = min(di, dj);
        sha.push_back({ci-cj,ci,ci+delta-1});
        ci += delta;
        cj += delta;
    }
    vector<int> dls;
    for(auto x : sha){
        dls.push_back(x.val);
    }
    sort(dls.begin(), dls.end());
    dls.resize(unique(dls.begin(), dls.end()) - dls.begin());
    for(auto &x : sha){
        x.val = lower_bound(dls.begin(), dls.end(), x.val) - dls.begin();
        segm[x.val].insert(mp(x.li, x.ri));
    }
    int ii, jj;
    int df;
    int it;
    for(int i = 0 ;i < q; i ++ ){
        cin >> ii >> jj;
        if(pp.count(mp(ii,jj))){
            cout << "LOSE\n";
            continue;
        }
        df = ii - jj;
        it = lower_bound(dls.begin(), dls.end(), df) - dls.begin();
        if(it < dls.size()){
            if(dls[it] == df){
                auto pi = segm[it].lower_bound(mp(ii+1,-1));
                if(pi != segm[it].begin()){
                    pi -- ;
                    if((pi->fi) <= ii && ii <= (pi->se)){
                        cout << "LOSE\n";
                    }
                    else{
                        cout << "WIN\n";
                    }
                }
                else{
                    cout << "WIN\n";
                }
            }
            else{
                cout << "WIN\n";
            }
        }
        else{
            cout << "WIN\n";
        }
    }
    return 0;
}