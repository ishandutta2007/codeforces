#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
using namespace std;

int n;
ld x,y;

struct polowa{
    int cnt_triangle;
    int sumx3;
    int sumy3;
    int bal;
};

int ary(int lo, int hi){
    return (hi - lo + 1) * (lo + hi) / 2;
}

polowa dawaj(vector<int> cur, int start = 0){

    bool dbg = true;
            for(int w : cur){
                if(w == -1) dbg = false;
            }

    polowa res;
    res.cnt_triangle = 0;
    res.sumx3 = 0;
    res.sumy3 = 0;
    res.bal = 0;
    int wys = start;
    int len = 0;
    for(int x : cur){
        int pop = wys;
        wys += x;
        res.cnt_triangle += (pop + wys);
        res.sumx3 += min(pop, wys) * 3;
        if(wys > pop){
            res.sumx3 += 2;
        }
        else res.sumx3 += 1;
        res.sumx3 += len * (pop + wys) * 3;
        res.sumy3 += min(pop, wys) * 3;
        res.sumy3 += min(pop, wys) * 3;
        res.sumy3++;
        res.sumy3 += ary(0, min(pop, wys) - 1) * 6;
        len++;
    }
    res.bal = wys;
    return res;
}

set<pair<pii, pii> > secik[999][22];

map<pair<pii, pii>, vector<int> > kto;

void solve(){
    cin >> n >> x >> y;
    vector<vector<int> > come;
    vector<polowa> pos;
    for(int i=0;i<(1<<n/2);i++){
        vector<int> cur;
        int bal = 0;
        bool ok = true;
        for(int j=0;j<n/2;j++){
            if(i & (1 << j)) cur.pb(1);
            else cur.pb(-1);
        }
        for(int x : cur){
            bal += x;
            if(bal < 0) ok = false;
        }
        if(ok){
            bool dbg = true;
            for(int w : cur){
                if(w == -1) dbg = false;
            }

            auto x = dawaj(cur);
            auto rev = cur;
            reverse(rev.begin(), rev.end());
            for(int i=0;i<rev.size();i++) rev[i] *= -1;
            auto yy = dawaj(rev, bal);
            yy.bal = bal;
            auto kt = mp(mp(yy.bal, yy.cnt_triangle), mp(yy.sumx3, yy.sumy3));
            secik[yy.cnt_triangle][yy.bal].insert(kt);
            kto[kt] = rev;
            pos.pb(dawaj(cur));
            come.pb(cur);
        }
    }

    for(int i=0;i<pos.size();i++){
        auto cur = pos[i];
        for(int to=0;to<444;to++){

            int pola = cur.cnt_triangle + to;

            ld edx = x * 3 * pola;
            ld edy = y * 3 * pola;

            ld ox = round(edx);
            ld oy = round(edy);
            int ex = round(edx);
            int ey = round(edy);
            ex -= cur.sumx3;
            ey -= cur.sumy3;
            ex -= (n / 2 * 3 * to);

            if(secik[to][cur.bal].size() == 0) continue;
            auto look_for = mp(mp(cur.bal, to), mp(ex, ey));
            if(secik[to][cur.bal].count(look_for)){
                auto it = secik[to][cur.bal].find(look_for);

                ld xxx = n/2*3*to + cur.sumx3 + ex;
                ld yyy = cur.sumy3 + ey;

                xxx /= pola;
                yyy /= pola;
                xxx /= 3;
                yyy /= 3;

                if(abs(xxx - x > 0.000000001) || abs(yyy - y) > 0.000000001) continue;

                vector<int> ent = kto[*it];
                vector<int> beg = come[i];

                for(int w : beg){
                    if(w == 1) cout <<"(";
                    else cout<<")";
                }
                for(int w :ent){
                    if(w == 1) cout <<"(";
                    else cout<<")";
                }
                cout<<"\n";
                exit(0);
            }


        }


    }



}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();



    return 0;
}