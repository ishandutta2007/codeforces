#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int A[N];
ll sigma = 0;
int n;

void upd(int id, int v){
    if(id <= 0) return;
    if(A[id] != A[id + 1]){
        sigma += v * 1ll * id * 1ll * (n - id);
    }
}

int main(){
    fastIO;
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    for(int i = 1; i < n; i ++ ){
        upd(i, +1);
    }
    int id, x;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> id >> x;
        upd(id, -1);
        upd(id-1, -1);
        A[id]=x;
        upd(id, +1);
        upd(id-1,+1);
        cout << sigma + n * 1ll * (n + 1) / 2ll << "\n";
    }
    return 0;
}