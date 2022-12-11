#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int nex[N];
int bit[N];
int id = 0;
vector<int> nds[N];
int iq[N];

vector<pii> edg;
int n;

void toggle(int x, int y){
    swap(nex[x], nex[y]);
    edg.push_back(mp(x, y));
    swap(bit[x], bit[y]);
    bit[x] ^= 1;
    bit[y] ^= 1;
}

void unite(vector<int> a, vector<int> c){
    toggle(a[0], c[0]);
    for(int i = 1; i < a.size() ; i ++ ){
        toggle(c[0], a[i]);
    }
    for(int i = 1; i < c.size() ; i ++ ){
        toggle(a[0], c[i]);
    }
    toggle(a[0], c[0]);
}

int main(){
    fastIO;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> nex[i];
    }
    int node;
    for(int i = 1; i <= n; i ++ ){
        if(iq[i] != 0) continue;
        id ++ ;
        node = i;
        while(iq[node] == 0){
            nds[id].push_back(node);
            iq[node]=id;
            node = nex[node];
        }
    }
    if(id % 2 == 0){
        for(int i = 1; i <= id ; i += 2){
            unite(nds[i], nds[i + 1]);
        }
    }
    else{
        int idx = -1;
        for(int i = 1; i <= id ; i ++ ){
            if(nds[i].size() != 2){
                idx = i;
            }
        }
        if(idx == -1){
            int A = nds[1][0];
            int B = nds[2][0];
            int C = nds[3][0];
            int D = nds[1][1];
            int E = nds[2][1];
            int F = nds[3][1];
            toggle(A,B);
            toggle(A,C);
            toggle(A,F);
            toggle(A,C);
            toggle(A,E);
            toggle(B,D);
            toggle(A,B);
            for(int j = 4; j <= id; j += 2){
                unite(nds[j], nds[j + 1]);
            }
        }
        else{
            if(nds[idx].size() > 1){
                int A = nds[idx][0];
                int B = nds[idx][1];
                int C = nds[idx][2];
                toggle(A,B);
                toggle(B,C);
                toggle(A,C);
                for(int i = 3; i < nds[idx].size(); i ++ ){
                    toggle(B, nds[idx][i]);
                }
                toggle(A,B);
            } // else - do nothing
            int las = -1;
            for(int i = 1; i <= id; i ++ ){
                if(i == idx) continue;
                if(las != -1){
                    unite(nds[i], nds[las]);
                    las = -1;
                }
                else{
                    las = i;
                }
            }
        }
    }
    cout << edg.size() << "\n";
    for(auto q : edg)
        cout << q.fi << " " << q.se << "\n";
    return 0;
}