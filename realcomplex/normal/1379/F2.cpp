#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;

struct Node{
    int low;
    int high;
    bool valid;
};

Node T[N * 4 + 512];

Node unite(Node A, Node B){
    Node sol;
    sol.valid = (A.valid | B.valid);
    sol.low = min(A.low, B.low);
    sol.high = max(A.high, B.high);
    if(A.low <= B.high) sol.valid = true;
    return sol;
}

set<int> L[N];
set<int> R[N];

void update(int node, int cl, int cr, int pos){
    if(cl == cr){
        int ai = (int)1e9;
        int bi = -1;
        if(!L[cl].empty()) ai = *L[cl].begin();
        if(!R[cl].empty()){
            auto it = R[cl].end();
            it -- ;
            bi = *it;
        }
        T[node] = {ai, bi, false};
        if(ai <= bi)
            T[node].valid = true;
        return;
    }
    int mid = (cl + cr) / 2;
    if(mid >= pos)
        update(node * 2, cl, mid, pos);
    else
        update(node * 2 + 1, mid + 1, cr, pos);
    T[node] = unite(T[node * 2], T[node * 2 + 1]);
}

int main(){
    fastIO;
    int n, m, qr;
    cin >> n >> m >> qr;
    for(int i = 0 ; i < N * 4 + 512;  i ++ ){
        T[i] = {(int)1e9, -1, false};
    }
    int xi, yi;
    int pp, qq;
    for(int t = 1; t <= qr; t ++ ){
        cin >> xi >> yi;
        xi -- ;
        yi -- ;
        pp = xi / 2;
        qq = yi / 2;
        if(xi % 2 == 0){
            if(L[pp].count(qq))L[pp].erase(qq);
            else L[pp].insert(qq);
        }
        else{
            if(R[pp].count(qq))R[pp].erase(qq);
            else R[pp].insert(qq);
        }
        update(1, 0, n - 1, pp);
        if(T[1].valid)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}