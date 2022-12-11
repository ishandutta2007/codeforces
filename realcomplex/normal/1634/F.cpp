#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 100;


int mod;

void cum(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

vector<int> turn(vector<int> C){
    vector<int> Q(C.size());
    for(int i = 0 ; i < C.size(); i ++ ){
        Q[i] = C[i];
        if(i - 1 >= 0) cum(Q[i], -C[i - 1]);
        if(i - 2 >= 0) cum(Q[i], -C[i - 2]);
    }
    return Q;
}
int n;

vector<int> A;
vector<int> B;

int F[N];

int eq = 0;

void add(char tt, int id, int val){
    if(id >= n) return;
    if(A[id] == B[id]) eq -- ;
    if(tt == 'A') cum(A[id], val);
    else cum(B[id], val);
    if(A[id] == B[id]) eq ++ ;
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int q;
    cin >> n >> q >> mod;
    A.resize(n);
    B.resize(n);
    for(int i = 0 ; i < n; i ++ ) cin >> A[i];
    for(int i = 0 ; i < n; i ++ ) cin >> B[i];
    A = turn(A);
    B = turn(B);
    for(int i = 0 ; i < n; i ++ ){
        if(A[i] == B[i]) eq ++ ;
    }
    F[1]=1;
    F[2]=1;
    for(int i = 3; i < N; i ++ ){
        F[i] = (F[i - 1] + F[i - 2]) % mod;
    }
    char type;
    int lef, rig;
    int cummy;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> type >> lef >> rig;
        lef -- ;
        rig -- ;
        cummy = (F[rig - lef + 1] + F[rig - lef]) % mod;
        add(type, lef, +1);
        add(type, rig + 1, -cummy);
        add(type, rig + 2, -F[rig - lef + 1]);
        if(eq == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}