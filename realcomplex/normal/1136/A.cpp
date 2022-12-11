#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n;
    cin >> n;
    int l[n], r[n];
    for(int i = 0 ; i < n; i ++ ){
        cin >> l[i] >> r[i];
    }
    int k;
    cin >> k;
    int answ = n;
    for(int i = 0 ; i < n ; i ++ ){
        if(r[i] >= k){
            break;
        }
        -- answ;
    }
    cout << answ;
    return 0;
}