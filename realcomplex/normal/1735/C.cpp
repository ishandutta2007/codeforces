#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int AL = 26;
int nex[AL];
int in[AL];

int fin(int u){
    while(nex[u] != u) u=nex[u];
    return u;
}

void solve(){
    int n;
    cin >> n;
    char f;
    int id;
    vector<int> res;
    for(int i = 0 ; i < AL; i ++ ){
        nex[i] = i;
        in[i]=false;
    }
    int mark = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> f;
        id=f-'a';
        if(nex[id] == id){
            for(int j = 0 ; j < AL; j ++ ){
                if(in[j] || j == id || (fin(j) == id && mark < 25)) continue;
                mark ++ ;
                in[j]=true;
                nex[id]=j;
                break;
            }
        }
        res.push_back(nex[id]);
    }
    for(auto p : res){
        cout << char(p + 'a');
    }
    cout << "\n";
}

int main(){
    fastIO;
   // freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
       solve();
    }
    return 0;
}