#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
int ca[N], cb[N];

void solve(){
    int n, lf, rf;
    cin >> n >> lf >> rf;
    vector<int> A;
    vector<int> B;
    int x;
    for(int i = 1; i <= lf ;i ++ ){
        cin >> x;
        A.push_back(x);
    }
    for(int i = 1; i <= rf; i ++ ){
        cin >> x;
        B.push_back(x);
    }
    if(lf > rf){
        swap(lf, rf);
        swap(A, B);
    }
    for(int i = 1; i <= n; i ++ ){
        ca[i] = cb[i] = 0;
    }
    for(auto x : A){
        ca[x] ++ ;
    }
    for(auto x : B){
        cb[x] ++ ;
    }
    int low;
    for(int i = 1; i <= n; i ++ ){
        low = min(ca[i], cb[i]);
        ca[i] -= low;
        cb[i] -= low;
        rf -= low;
        lf -= low;
    }
    int op = rf - ((lf + rf) / 2);
    int cost = 0;
    for(int i = 1; i <= n; i ++ ){
        while(cb[i] >= 2 && op > 0){
            cb[i] -= 2;
            op -- ;
            cost ++ ;
        }
    }
    for(int i = 1; i <= n; i ++ ){
        while(cb[i] >= 1 && op > 0){
            cb[i] -- ;
            ca[i] ++ ;
            op -- ;
            cost ++ ;
        }
        low = min(ca[i], cb[i]);
        ca[i] -= low;
        cb[i] -= low;
        cost += ca[i];
    }
    cout << cost << "\n";

}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}