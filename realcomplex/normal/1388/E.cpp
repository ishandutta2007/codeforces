#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2005;
const ld inf = (ld)1e18;
ld xl[N], xr[N], yy[N];

struct line{
    ld lx;
    ld rx;
    ld yt;
    bool operator<(const line &f) const {
        return yt < f.yt;
    }
};

struct hull_line{
    ld ai;
    ld bi;
    ld lim;
};

ld intersect(ld a1, ld b1, ld a2, ld b2){
    return (b1-b2)/(a2-a1);
}

void add_p(vector<hull_line> &co, hull_line ff){
    if(co.empty()){
        co.push_back(ff);
    }
    else{
        if(co.back().ai == ff.ai){
            if(co.back().bi >= ff.bi){
                return;
            }
            co.pop_back();
        }
        hull_line p1, p2;
        while(co.size() >= 2){
            p1 = co[co.size() - 1];
            p2 = co[co.size() - 2];
            if(intersect(ff.ai, ff.bi, p2.ai, p2.bi) >= intersect(ff.ai, ff.bi, p1.ai, p1.bi))
                co.pop_back();
            else
                break;
        }
        if(!co.empty()){
            co.back().lim = intersect(ff.ai, ff.bi, co.back().ai, co.back().bi);
        }
        co.push_back(ff);
    }
}

ld get(vector<hull_line> cco, ld lt){
    int l = 0, r = cco.size()-1;
    int mid;
    while(l < r){
        mid = (l + r) / 2;
        if(cco[mid].lim < lt)
            l = mid + 1;
        else
            r = mid;
    }
    return cco[l].ai * lt + cco[l].bi;
}

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<line> con;
    for(int i = 0 ; i < n; i ++ ){
        cin >> xl[i] >> xr[i] >> yy[i];
        con.push_back({xl[i], xr[i], yy[i]});
    }
    sort(con.begin(), con.end());
    vector<pdd> ss;
    ss.push_back(mp(0,0)); // corner case
    ld bi, bj;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0; j < n; j ++ ){
            if(yy[i] > yy[j]){
                bi = (xl[j]-xr[i])/(yy[i]-yy[j]);
                bj = (xr[j]-xl[i])/(yy[i]-yy[j]);
                ss.push_back(mp(bi,+1));
                ss.push_back(mp(bj,-1));
            }
        }
    }
    sort(ss.begin(), ss.end());
    int cnt = 0;
    bool bad = true;
    vector<hull_line> up, down;
    for(auto p : con){
        add_p(up, {p.yt, p.rx, +inf});
    }
    reverse(con.begin(), con.end());
    for(auto p : con){
        add_p(down, {-p.yt, -p.lx, +inf});
    }
    ld sol = (ld)1e18;
    for(auto p : ss){
        bad = false;
        if(cnt == 0) bad = true;
        cnt += p.se;
        if(cnt == 0) bad = true;
        if(bad){
            sol = min(sol,get(up,p.fi) + get(down,p.fi));
        }
    }
    cout << fixed << setprecision(10) << sol << "\n";
    return 0;
}