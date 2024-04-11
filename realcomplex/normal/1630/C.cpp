#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
vector<int> occ[N];
int A[N];
int B[N];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        occ[A[i]].push_back(i);

    }
    vector<pii> segm;
    for(int i = 1; i <= n; i ++ ){
        if(occ[i].size() > 1){
            segm.push_back(mp(occ[i][0], occ[i].back()));
        }
    }
    sort(segm.begin(), segm.end());
    int maxi;
    vector<pii> upd;
    maxi = 0;
    for(auto x : segm){
        if(x.se < maxi){
            continue;
        }
        upd.push_back(mp(x.fi, x.se));
        maxi = x.se;
    }
    int lef, rig;
    int keep = 0;
    int last = 0;
    int cnt = 0;
    for(int iq = 0 ; iq < upd.size(); iq ++ ){
        lef = upd[iq].fi;
        rig = upd[iq].se;
        B[lef] ++ ;
        B[rig + 1] -- ;

        if(upd[iq].fi > last){
            keep += 2;
            last = upd[iq].se;
            cnt ++ ;
        }
        else{
            if(iq + 1 < upd.size()){
                if(upd[iq + 1].fi < last){
                    continue;
                }
            }
            keep ++ ;
            last = upd[iq].se;
            cnt ++ ;
        }
    }
    int cover = 0;
    for(int i = 1; i <= n; i ++ ){
        B[i] += B[i - 1];
        if(B[i] > 0){
            cover ++ ;
        }
    }
    cout << cover - keep;
    return 0;
}