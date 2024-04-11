#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int LOG = 17;
const int N = (1<<LOG);
const int T = N * LOG + 100;

int trie[T][2];
int id;

void solve(){
    int l, r;
    cin >> l >> r;
    for(int i = 0 ; i <= id; i ++ ){
        trie[i][0] = trie[i][1] = -1;
    }
    id = 0;
    vector<int> xx;
    int a;
    int go;
    int b;
    for(int i = l ; i <= r; i ++ ){
        cin >> a;
        go = 0;
        for(int j = LOG - 1; j >= 0 ; j -- ){
            if((a & (1 << j))) b = 1;
            else b = 0;
            if(trie[go][b] == -1){
                id ++ ;
                trie[go][b] = id;
            }
            go = trie[go][b];
        }
        xx.push_back(a);
    }
    int k;
    int maxi;
    int low;
    for(auto x : xx){
        k = (x ^ l);
        go = 0;
        maxi = 0;
        for(int lg = LOG - 1; lg >= 0 ; lg -- ){
            if((k & (1 << lg))){
                b = 1;
            }
            else{
                b = 0;
            }
            if(trie[go][1-b] != -1) {
                go = trie[go][1 - b];
                //cout << go << " " << 1 - b << " " << lg << "!!\n";
                maxi += (1 << lg);
            }
            else{
                go = trie[go][b];
            }
        }
        low = 0;
        go = 0;
        for(int lg = LOG - 1; lg >= 0 ; lg -- ){
            if((k & (1 << lg))){
                b = 1;
            }
            else{
                b = 0;
            }
            if(trie[go][b] != -1) {
                go = trie[go][b];
            }
            else{
                go = trie[go][1-b];
                low += (1 << lg);
            }
        }
        //cout << low << " " << maxi << "\n";
        if(low == l && maxi == r){
            cout << k << "\n";
            return;
        }
    }

    cout << -1 << "\n";

}


int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    for(int i = 0; i < T; i ++ ){
        trie[i][0] = trie[i][1] = -1;
    }
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}