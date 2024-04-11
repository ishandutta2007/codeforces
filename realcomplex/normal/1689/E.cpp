#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int LOG = 31;
const int N = 2050;

bool has[LOG];
vector<int> id[LOG];
bool vis[N];

bool correct(vector<int> t){
    int n = t.size();
    for(int i = 0 ; i < LOG; i ++) {
        has[i]=false;
        id[i].clear();
    }
    for(int i = 0 ; i < n ; i ++ ) {
        vis[i]=false;
        for(int j = 0 ; j < LOG; j ++ ){
            if((t[i] & (1 << j))){
                id[j].push_back(i);
            }
        }
    }
    queue<int> que;
    que.push(0);
    vis[0]=true;
    int node;
    while(!que.empty()){
        node = que.front();
        que.pop();
        for(int i = 0 ; i < LOG; i ++ ){
            if((t[node] & (1 << i))){
                if(!has[i]){
                    for(auto x : id[i]){
                        if(!vis[x]){
                            vis[x]=true;
                            que.push(x);
                        }
                    }
                    has[i]=true;
                }
            }
        }
    }
    for(int i = 0 ; i < n; i ++ ){
        if(vis[i] == false) return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    int op = 0;
    for(int i = 0 ; i < n; i ++ ){
        cin >> A[i];
        if(A[i] == 0){
            op ++ ;
            A[i] ++ ;
        }
    }
    if(correct(A)){
        cout << op << "\n";
        for(auto x : A) cout << x << " ";
        cout << "\n";
        return;
    }
    for(int i = 0 ; i < n; i ++ ){
        A[i] ++ ;
        if(correct(A)){
            cout << op + 1 << "\n";
            for(auto x : A) cout << x << " ";
            cout << "\n";
            return;
        }
        A[i] -= 2;
        if(correct(A)){
            cout << op + 1 << "\n";
            for(auto x : A) cout << x << " ";
            cout << "\n";
            return;
        }
        A[i] ++ ;
    }
    int maxi = 0;
    vector<int> dd;
    int qq;
    for(int i = 0 ; i < n; i ++ ){
        qq = 0;
        for(int j = 0 ; j < LOG; j ++ ){
            if((A[i] & (1 << j))){
                qq = (1 << j);
                break;
            }
        }
        if(qq > maxi){
            maxi = qq;
            dd = {i};
        }
        else if(qq == maxi){
            if(dd.size() < 2)
                dd.push_back(i);
        }
    }
    int pa = dd[0];
    int qa = dd[1];
    A[pa] -- ;
    A[qa] ++ ;
    cout << op + 2 << "\n";
    for(auto x : A)
        cout << x << " ";
    cout << "\n";


}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}