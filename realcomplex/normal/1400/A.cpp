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
    int tc;
    cin >> tc;
    for(int ttt = 0 ;ttt  < tc; ttt ++ ){
        int n;
        cin >> n;
        string t;
        cin >> t;
        for(int i = 0 ; i < t.size(); i += 2 )
            cout << t[i];
        cout << "\n";
    }
    return 0;
}