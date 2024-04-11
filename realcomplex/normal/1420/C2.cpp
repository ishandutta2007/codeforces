#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 100;
const ll inf = (ll)1e12;

ll T[N * 4 + 512][4];

void setv(int node, int cl, int cr, int pos, ll v){
    if(cl == cr){
        T[node][0] = v;
        T[node][3] = -v;
        return;
    }
    int mid = (cl + cr) / 2;
    if(mid >= pos)
        setv(node * 2, cl, mid, pos, v);
    else
        setv(node * 2 + 1, mid + 1, cr, pos, v);
    for(int i = 0 ; i < 4; i ++ )
        T[node][i]=max(T[node*2][i],T[node*2+1][i]);
    for(int i = 0 ;i < 4; i ++ ){
        for(int j = 0; j < 4; j ++ ){
            if((i%2) != (j/2))
                T[node][(i&2)|(j&1)] = max(T[node][(i&2)|(j&1)], T[node*2][i] + T[node*2+1][j]);
        }
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ ){
        int n, q;
        cin >> n >> q;
        for(int i = 0 ; i <= 4 * n + 12; i ++ ){
            for(int j = 0 ;j < 4; j ++ )
                T[i][j] = -inf;
        }
        vector<ll> x(n);
        for(int i = 0; i < n; i ++ ){
            cin >> x[i];
            setv(1, 0, n-1, i, x[i]);
        }
        int l, r;
        int pi, qi;
        cout << max(T[1][0],T[1][1]) << "\n";
        for(int i = 0 ;i < q; i ++ ){
            cin >> l >> r;
            l--;
            r--;
            swap(x[l],x[r]);
            setv(1, 0, n - 1, l, x[l]);
            setv(1, 0, n - 1, r, x[r]);
            cout <<  max(T[1][0],T[1][1]) << "\n";
        }
    }
    return 0;
}