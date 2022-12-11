#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int K = 18;
const int N = (1 << K);

struct Node{
    int val;
    int state;
};

Node T[N];

vector<int> path[N];

int n;

void dfs(int node,vector<int> cur){
    cur.push_back(node);
    path[node] = cur;
    if(node * 2 < n){
        dfs(node * 2, cur);
        if(T[node].state == 0 || T[node].state == 2)
            T[node].val += T[node * 2].val;
    }
    else{
        if(T[node].state == 0 || T[node].state == 2)
            T[node].val += 1;
    }
    if(node * 2 + 1 < n){
        dfs(node * 2 + 1, cur);
        if(T[node].state == 1 || T[node].state == 2)
            T[node].val += T[node * 2 + 1].val;
    }
    else{
        if(T[node].state == 1 || T[node].state == 2)
            T[node].val += 1;
    }
}

int main(){
    fastIO;
    int k;
    cin >> k;
    n = (1 << k);
    char f;
    for(int i = n - 1; i > 0; i -- ){
        cin >> f;

        if(f == '0')
            T[i].state = 1;
        else if(f == '1')
            T[i].state = 0;
        else
            T[i].state = 2;

    }
    dfs(1, {});
    int q;
    cin >> q;
    int ch;
    int node;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> ch >> f;
        ch = n - ch;
        for(int j = path[ch].size() - 1; j >= 0 ; j -- ){
            node = path[ch][j];
            if(j + 1 == path[ch].size()){
                if(f == '0')
                    T[node].state = 1;
                else if(f == '1')
                    T[node].state = 0;
                else
                    T[node].state = 2;
            }
            T[node].val = 0;
            if(node * 2 < n){
                if(T[node].state == 0 || T[node].state == 2)
                    T[node].val += T[node * 2].val;
            }
            else{
                if(T[node].state == 0 || T[node].state == 2)
                    T[node].val += 1;
            }
            if(node * 2 + 1 < n){
                if(T[node].state == 1 || T[node].state == 2)
                    T[node].val += T[node * 2 + 1].val;
            }
            else{
                if(T[node].state == 1 || T[node].state == 2)
                    T[node].val += 1;
            }
        }
        cout << T[1].val << "\n";
    }
    return 0;
}