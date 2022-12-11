#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int LOG = 30;
int par[LOG][N];
int B[N];
bool has[N];

vector<int> posi[N];
int res[N];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> par[0][i];
        has[par[0][i]]=true;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++ ){
        if(!has[i]) cnt ++ ;
    }
    int mx = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> B[i];
        mx = max(mx, B[i]);
    }
    int K = (mx-n)/cnt;
    for(int i = 1; i < LOG; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }
    int go;
    for(int i = 1; i <= n; i ++ ){
        go = i;
        for(int j = LOG - 1; j >= 0 ; j -- ){
            if((K & (1 << j))){
                go = par[j][go];
            }
        }
        if(B[go] <= n){
            posi[B[go]].push_back(i);
        }
    }
    set<int> low;
    for(int i = 1; i <= n; i ++ ){
        sort(posi[i].begin(), posi[i].end());
        if(!posi[i].empty()){
            res[posi[i][0]] = i;
            for(int j = 1; j < posi[i].size(); j ++ ){
                low.insert(posi[i][j]);
            }
        }
        else{
            res[*low.begin()] = i; // if low is empty no answer since i must be eliminated
            low.erase(low.begin());
        }
    }
    for(int i = 1; i <= n; i ++ ){
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}