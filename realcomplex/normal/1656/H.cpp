#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef __int128 lli;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
void in(lli &x){
    string t;
    cin >> t;
    x = 0;
    for(char v : t){
        x *= 10ll;
        x += (v - '0');
    }
}

void outp(lli x){
    vector<int> d;
    do{
        d.push_back(x%10ll);
        x /= 10ll;
    }while(x > 0);
    reverse(d.begin(), d.end());
    for(auto b : d) cout << b;
}

lli gcd(lli a, lli b){
    while(a != 0){
        b %= a;
        swap(a, b);
    }
    return b;
}

struct segment_tree{
    lli T[N * 4];
    lli D;
    int m;
    vector<lli> ini;
    void init(int node, int cl, int cr){
        if(cl == cr){
            T[node] = D/gcd(D, ini[cl]);
            return;
        }
        int mid = (cl + cr) / 2;
        init(node * 2, cl, mid);
        init(node * 2 + 1, mid + 1, cr);
        T[node] = gcd(T[node * 2], T[node * 2 + 1]);
    }
    void build(lli C, vector<lli> X){
        D = C;
        m = X.size();
        ini = X;
        init(1, 0, m - 1);
    }
    void disable(int node, int cl, int cr, int id){
        if(cl == cr){
            T[node] = 0;
            return;
        }
        int mid = (cl + cr) / 2;
        if(mid >= id)
            disable(node * 2, cl, mid, id);
        else
            disable(node * 2 + 1, mid + 1, cr, id);
        T[node] = gcd(T[node * 2], T[node * 2 + 1]);
    }

};

segment_tree ai[N], bi[N];
bool da[N], db[N];

void solve(){
    int n, m;
    cin >> n >> m;
    vector<lli> A(n);
    vector<lli> B(m);
    for(int i = 0; i < n; i ++ ) in(A[i]);
    for(int i = 0; i < m; i ++ ) in(B[i]);
    for(int i = 0 ; i < n; i ++ ){
        da[i] = false;
        ai[i].build(A[i], B);
    }
    for(int i = 0 ; i < m ; i ++ ){
        db[i] = false;
        bi[i].build(B[i], A);
    }
    bool bad = true;
    int ca = n, cb = m;
    while(bad && ca > 0 && cb > 0){
        bad = false;
        for(int i = 0 ; i < n; i ++ ){
            if(da[i] == false && ai[i].T[1] > 1){
                for(int j = 0 ; j < m ; j ++ ){
                    if(db[j] == false){
                        bi[j].disable(1, 0, n - 1, i);
                    }
                }
                da[i] = true;
                bad = true;
                ca -- ;
                break;
            }
        }
        if(!bad){
            for(int i = 0 ; i < m ; i ++ ){

                if(db[i] == false && bi[i].T[1] > 1){
                    for(int j = 0 ; j < n; j ++ ){
                        if(da[j] == false){
                            ai[j].disable(1, 0, m - 1, i);
                        }
                    }
                    db[i] = true;
                    bad = true;
                    cb -- ;
                    break;
                }
            }
        }
    }
    if(ca == 0 || cb == 0){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << ca << " " << cb << "\n";
    for(int i = 0 ; i < n; i ++ ){
        if(da[i] == 0){
            outp(A[i]);
            cout << " ";
        }
    }
    cout << "\n";
    for(int i = 0 ; i < m ; i ++ ){
        if(db[i] == 0){
            outp(B[i]);
            cout << " ";
        }
    }
    cout << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}