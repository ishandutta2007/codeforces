#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc ; t ++ ){
        int n, m;
        cin >> n >> m;
        vector<int> ids(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> ids[i];
            ids[i]--;
        }
        sort(ids.begin(), ids.end());
        vector<int> cc(m);
        for(int i = 0 ; i < m ; i ++ ){
            cin >> cc[i];
        }
        int p = 0;
        ll sol = 0;
        for(int i = n - 1; i >= 0 ; i -- ){
            if(p <= ids[i]){
                sol += cc[p];
                p ++ ;
            }
            else{
                sol += cc[ids[i]];
            }
        }
        cout << sol << "\n";
    }
    return 0;
}