#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1010;

int bit[N];
int flip[N];
int n;

int gen(int mod){
    return ((int)rng() % mod + mod) % mod;
}

int ask(){
    for(int i = 0 ; i < n; i ++ ){
        if(bit[i] == 0) cout << "F";
        else cout << "T";
    }
    cout << endl;
    int res;
    cin >> res;
    if(res == n) exit(0);
    return res;
}

void f(int id){
    bit[id] ^= 1;
}

int base;

void shuffle(vector<int> &a){
    if(a.empty()) return;
    int m = a.size();
    int x, y;
    for(int i = 0 ; i < 4 * m ; i ++ ){
        x = gen(m);
        y = gen(m);
        swap(a[x], a[y]);
    }
}

vector<int> sa, sb;

void solve(vector<int> ids, int correct){
    if(correct == 0){
        for(auto i : ids){
            flip[i] = 1;
        }
        return;
    }
    if(correct == ids.size()){
        for(auto i : ids){
            flip[i] = 0;
        }
        return;
    }
    shuffle(ids);
    if(ids.size() == 2){
        sa.push_back(ids[0]);
        sb.push_back(ids[1]);
        return;
    }
    int mid = ids.size() / 2;
    vector<int> lef;
    vector<int> rig;
    for(int i = 0 ; i < ids.size(); i ++ ){
        if(i < mid){
            lef.push_back(ids[i]);
            f(ids[i]);
        }
        else{
            rig.push_back(ids[i]);
        }
    }
    int cur = ask();
    for(auto i : lef) f(i);
    int nex = (base + (int)lef.size() - cur) / 2;
    solve(lef, nex);
    solve(rig, correct - nex);
}

void get_data(vector<int> ss){
    int cur;
    if(ss.size() <= 3){
        for(auto x : ss){
            f(x);
            cur = ask();
            if(cur > base){
                flip[x] = 1;
            }
            else{
                flip[x] = 0;
            }
            f(x);
        }
        return;
    }
    shuffle(ss);
    vector<int> ai, bi;

    for(int i = 0 ; i < ss.size(); i += 2){
        if(i + 1 < ss.size()){
            f(ss[i]);
            f(ss[i+1]);
            cur = ask();
            if(cur > base){
                flip[ss[i]] = 1;
                flip[ss[i+1]] = 1;
            }
            else if(cur < base){
                flip[ss[i]] = 0;
                flip[ss[i+1]] = 0;
            }
            else{
                ai.push_back(ss[i]);
                bi.push_back(ss[i+1]);
            }
            f(ss[i]);
            f(ss[i+1]);
        }
        else{
            ai.push_back(ss[i]);
            bi.push_back(-1);
        }
    }
    get_data(ai);
    for(int i = 0 ; i < ai.size(); i ++ ){
        if(bi[i] != -1){
            flip[bi[i]] = (flip[ai[i]] ^ 1);
        }
    }

}

int main(){
    cin >> n;
    vector<int> ii;
    for(int i = 0 ; i < n; i ++ ){
        bit[i] = gen(2);
        ii.push_back(i);
        flip[i] = -1;
    }
    base = ask();
    solve(ii, base);
    get_data(sa);
    for(int i = 0 ; i < sa.size(); i ++ ){
        flip[sb[i]] = (flip[sa[i]] ^ 1);
    }
    for(int i = 0 ; i < n; i ++ ){
        bit[i] ^= flip[i];
    }
    ask();
    return 0;
}