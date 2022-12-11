#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string sub(string q){
    for(int i = q.size() - 1; i >= 0 ; i -- ){
        if(q[i] == '1'){
            q[i] = '0';
            break;
        }
        q[i]='1';
    }
    return q;
}


int main(){
    fastIO;
    int n;
    cin >> n;
    string l, r;
    cin >> l >> r;
    if(l[0] != r[0]){
        for(int i = 0 ; i < n;i ++ )
            cout << 1;
        return 0;
    }
    string gag;
    for(int i = 0 ; i < n; i ++)
        gag.push_back('0');
    string sol = gag;
    for(int i = 0 ; i <= 2; i ++ ){
        for(int i = 0 ; i < n; i ++ ){
            if(r[i] == '1'){
                if(gag[i] == '0') gag[i] = '1';
                else gag[i] = '0';
            }
        }
        sol = max(sol, gag);
        if(r == l) break;
        r=sub(r);
    }
    cout << sol << "\n";
    return 0;
}