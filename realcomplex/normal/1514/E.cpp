#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 101;

int get(int i, int j){
    cout << 1 << " " << i << " " << j << endl;
    fflush(stdout);
    int val;
    cin >> val;
    return val;
}

vector<int> solve(vector<int> ids){
    if(ids.size() == 1) return ids;
    vector<int> lef, rig;
    for(int i = 0 ; i < ids.size(); i ++ ){
        if(i < ids.size() / 2){
            lef.push_back(ids[i]);
        }
        else{
            rig.push_back(ids[i]);
        }
    }
    lef = solve(lef);
    rig = solve(rig);
    vector<int> soln;
    int pa = 0, pb = 0;
    while(pa < lef.size() || pb < rig.size()){
        if(pa < lef.size() && (pb == rig.size() || get(lef[pa], rig[pb]))){
            soln.push_back(lef[pa]);
            pa ++ ;
        }
        else{
            soln.push_back(rig[pb]);
            pb ++ ;
        }
    }
    return soln;
}

int outp[N][N];

void solve(){
    int n;
    cin >> n;
    vector<int> gg;
    for(int i = 0 ; i < n; i ++ ){
        gg.push_back(i);
    }
    for(int i = 0 ;i  < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            outp[i][j]=0;
        }
    }
    gg = solve(gg);
    int p = n - 1;
    int las = n;
    int cond;
    vector<int> shit;
    for(int i = n - 1; i >= 0 ;i  -- ){
        while(p > 0){
            shit.clear();
            for(int q = 0; q < p ; q ++ ){
                shit.push_back(gg[q]);
            }
            cout << 2 << " " << gg[i] << " " << shit.size() << " ";
            for(auto x : shit)
                cout << x << " ";
            cout << endl;
            fflush(stdout);
            cin >> cond;
            if(cond)
                p -- ;
            else
                break;
        }
        if(i == p){
            for(int j = p; j < las; j ++ ){
                for(int f = j ;f >= p; f -- ){
                    outp[gg[j]][gg[f]]=1;
                }
            }
            las = i;
            p -- ;
            continue;
        }

    }
    for(int i = 0 ;i  < n; i ++ ){
        for(int j = i ;j < n; j ++ ){
            outp[gg[i]][gg[j]]=1;
        }
    }
    cout << 3 << "\n";
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0; j < n; j ++ ){
            cout << outp[i][j];
        }
        cout << endl;
    }
    fflush(stdout);
    int gag;
    cin >> gag;
}

int main(){
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}