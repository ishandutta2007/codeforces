#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2005;
int dist[N][N];
int n;
void ask(int node){
    cout << "? " << node << endl;
    for(int i = 1; i <= n; i ++ ){
        cin >> dist[node][i];
    }
}

int main(){
    fastIO;
    cin >> n;
    ask(1);
    vector<int> odd, even;
    for(int i = 1; i <= n; i ++ ){
        if(dist[1][i] % 2 == 0){
            even.push_back(i);
        }
        else{
            odd.push_back(i);
        }
    }
    vector<pii> E;
    if(even.size() <= odd.size()){
        for(auto x : even){
            if(x != 1){
                ask(x);
            }
            for(int j = 1; j <= n; j ++ ){
                if(dist[x][j] == 1){
                    E.push_back(mp(x,j));
                }
            }
        }
    }
    else{
        for(auto x : odd){
            if(x != 1){
                ask(x);
            }
            for(int j = 1; j <= n; j ++ ){
                if(dist[x][j] == 1){
                    E.push_back(mp(x, j));
                }
            }
        }
    }
    cout << "!" << endl;
    for(auto x : E){
        cout << x.fi << " " << x.se << endl;
    }
    return 0;
}