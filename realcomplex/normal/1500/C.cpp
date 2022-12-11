#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1510;
int cnt[N];
bool rel[N];

int id;
vector<vector<int>> a, b;
bool comp(int u, int v){
    return a[u][id] < a[v][id];
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    a.resize(n);
    b.resize(n);
    for(int i = 0 ;i < n; i ++ ){
        a[i].resize(m);
        for(int j = 0; j < m ; j ++ ){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i ++ ){
        b[i].resize(m);
        for(int j = 0; j < m ; j ++ ){
            cin >> b[i][j];
        }
    }
    if(a == b){
        cout << "0\n";
        return 0;
    }
    queue<int> qaq;
    for(int i = 0 ; i + 1 < n; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            if(b[i][j] > b[i+1][j]){
                cnt[j]++;
            }
        }
    }
    for(int i = 0 ; i < m ; i ++ ){
        if(cnt[i] == 0) qaq.push(i);
    }
    int node;
    vector<int> ord;
    while(!qaq.empty()){
        node = qaq.front();
        ord.push_back(node);
        qaq.pop();
        for(int i = 0 ; i + 1 < n; i ++ ){
            if(!rel[i] && b[i][node] != b[i+1][node]){
                rel[i]=true;
                for(int j = 0 ; j < m ; j ++ ){
                    if(cnt[j] > 0 && b[i][j] > b[i + 1][j]){
                        cnt[j] -- ;
                        if(cnt[j] == 0) qaq.push(j);
                    }
                }
            }
        }
    }
    reverse(ord.begin(), ord.end());
    vector<int> mat;
    for(int i = 0 ; i < n; i ++){
        mat.push_back(i);
    }
    for(auto x : ord){
        id = x;
        stable_sort(mat.begin(), mat.end(), comp);
    }
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < m ;j ++ ){
            if(a[mat[i]][j] != b[i][j]){
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << ord.size() << "\n";
    for(auto x : ord)
        cout << x + 1 << " ";
    cout << "\n";
    return 0;
}