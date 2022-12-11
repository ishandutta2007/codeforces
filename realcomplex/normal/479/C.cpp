#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n;
    cin >> n;
    pair<int,int>ex[n];
    for(int j = 0;j<n;j++){
        cin >> ex[j].fi >> ex[j].se;
    }
    sort(ex,ex+n);
    int cnt = -1;
    for(int i = 0;i<n;i++){
        if(ex[i].se >= cnt){
            cnt = ex[i].se;
        }
        else{
            cnt = ex[i].fi;
        }
    }
    cout << cnt;
    return 0;
}