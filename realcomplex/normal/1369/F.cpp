#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;
int win[N][N];

int canWin(ll i, ll j){
    if(j % 2 == 1){
        if(i % 2 == 1) return 0;
        return 1;
    } // by induction
    if(i * 2ll > j){
        return (j-i)%2;
    }
    if(i*4ll>j){
        return 1;
    }
    return canWin(i,j/4);
}

int canLose(ll i, ll j){
    if(i * 2ll > j) return 1;
    return canWin(i,j/2);
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    ll sa, sb;
    int ca, cb;
    vector<bool> cur(2);
    cur[1]=true;
    for(int i = 0 ; i < tc; i ++ ){
        cin >> sa >> sb;
        ca = canWin(sa,sb);
        cb = canLose(sa,sb);
        vector<bool> nx(2);
        if(cur[1]){
            if(cb) nx[1]=true;
            if(ca) nx[0]=true;
        }
        if(cur[0]){
            if(!ca) nx[0]=true; // can win
            if(!cb) nx[1]=true;
        }
        cur = nx;
    }
    for(auto x : cur)
        cout << x << " ";

    return 0;
}