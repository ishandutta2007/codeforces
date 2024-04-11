#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;
const int K = 350;
int A[N];
int B[N];
int id[N];
int lef[N];
int rig[N];
int tot[N];
bool block[N];

void compute(int bl){
    if(tot[bl] >= K) return; // no need to recompute
    for(int i = lef[bl] ; i <= rig[bl]; i ++ ){
        if(A[i] - tot[bl] < lef[bl]){
            B[i]=i;
        }
        else{
            B[i]=B[A[i]-tot[bl]];
        }
    }
}

int gob(int idx){
    if(tot[id[idx]] >= K) return idx;
    return B[idx];
}

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    int sz = K + 1;
    int cnt = 0;
    for(int i = 2; i <= n; i ++) {
        cin >> A[i];
        sz ++ ;
        if(sz > K){
            cnt ++ ;
            sz = 1;
            lef[cnt] = i;
        }
        rig[cnt]=i;
        id[i]=cnt;
    }
    for(int i = 2; i <= n; i ++ ){
        if(rig[id[i]] == i) compute(id[i]);
    }
    int typ;
    int li, ri, x;
    int lf, rf;
    for(int i = 1; i <= q; i ++ ){
        cin >> typ;
        if(typ == 1){
            cin >> li >> ri >> x;
            lf = li;
            rf = ri;
            while(li <= ri){
                if(lef[id[li]] == li && rig[id[li]] <= ri){
                    if(tot[id[li]] < n){
                        tot[id[li]] += x;
                        compute(id[li]);
                    }
                    li = rig[id[li]] + 1;
                }
                else{
                    A[li] = max(1, A[li] - x);
                    if(li == rig[id[li]] || li == rf) compute(id[li]);
                    li ++ ;
                }
            }
        }
        else{
            cin >> li >> ri;

            while(li != ri){
                if(li > ri) swap(li, ri);
                if(id[li] == id[ri]){
                    if(gob(li) == gob(ri)){
                        ri = max(1, A[ri] - tot[id[ri]]); // walk by one
                    }
                    else{
                        ri = gob(ri);
                        ri = max(1, A[ri] - tot[id[ri]]); // jump out of the block
                    }
                }
                else{
                    ri = gob(ri);
                    ri = max(1, A[ri] - tot[id[ri]]);
                }
            }
            cout << ri << "\n";
        }
    }
    return 0;
}