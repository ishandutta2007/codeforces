#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct magic_set{
    set<pii> segm; // set * sign
    ll sign = +1;
    ll pivot = 0ll;
    void output_set(){
        for(auto q : segm){
            cout << q.fi * sign + pivot << " " << q.se * sign + pivot << "\n";
        }
        cout << "--------\n";
    }
    bool contains(ll li, ll ri, ll pop){
        if(li <= pop && pop <= ri) return true;
        if(ri <= pop && pop <= li) return true;
        return false;
    }
    ll ga, gb;
    void delet(ll bound){ // delet all >= bound
        ll la, lb;
        while(!segm.empty()){
            auto it = segm.begin();
            if(sign == +1){
                it = segm.end();
                it -- ;
            }
            la = it->fi * sign + pivot;
            lb = it->se * sign + pivot;
            if(la >= bound && lb >= bound){
                segm.erase(it);
            }
            else{
                if(la < bound && lb < bound) break;
                segm.erase(it);
                la = min(la, bound - 1);
                lb = min(lb, bound - 1);
                segm.insert(mp((la-pivot)/sign, (lb-pivot)/sign));
                break;
            }
        }
    }
    void flip(ll x){
        sign = -sign;
        pivot = x - pivot;
    }
    bool check(ll li){
        // segments are non-intersecting
        li = (li - pivot) / sign; // real value
        auto it = segm.lower_bound(mp(li, -(ll)1e18));
        if(it != segm.end() && contains(it->fi, it->se, li)) return true;
        if(it != segm.begin()){
            it -- ;
            if(contains(it->fi, it->se, li)) return true;
        }
        return false;
    }
    void add(ll li, ll ri){
        if(check(li) || check(ri)) return;
        segm.insert(mp((li - pivot) / sign, (ri - pivot) / sign));
    }
    void clean(){
        segm.clear();
        pivot = 0;
        sign = +1;
    }
};

const int N = (int)5e5 + 10;
ll A[N];


void solve(){
    int n;
    cin >> n;
    magic_set dud;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    ll sol = 0;
    if(A[1] % 2 == 0)
        dud.add(A[1] / 2ll, A[1] / 2ll);
    ll two = -1;
    ll x;
    int add;
    for(int i = 2; i <= n; i ++ ){
        x = A[i];
        if(two == -1){
            if(dud.segm.empty()){
                dud.add(1, min(x - 1, A[i - 1] - 1));
                dud.flip(x);
                if(x % 2 == 0){
                    if(x / 2 <= A[i - 1] - 1){
                        two = x / 2;
                    }
                    dud.add(x / 2, x / 2);
                }
            }
            else{
                sol += 1;
                add = -1;
                if(x % 2 == 0){
                    if(dud.check(x / 2)) add = 2;
                    else if(x / 2 <= A[i - 1] - 1) add = 1;
                }
                dud.delet(x);
                dud.flip(x);
                if(add == 2)
                    two = x / 2;
                if(x % 2 == 0)
                    dud.add(x / 2, x / 2);
            }
        }
        else{
            sol += 2;
            dud.clean();
            if(two < x){
                dud.add(x-two, x-two);
            }
            if(x % 2 == 0){
                dud.add(x / 2, x / 2); // transition from maximum
                if(x / 2 != two){
                    two = -1;
                }
            }
            else{
                two = -1;
            }
        }
    }
    if(two != -1) {
        sol += 2;
    }
    else if(dud.segm.size() > 0){
        sol ++ ;
    }
    cout << n * 2 - sol << "\n";
    return;
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}