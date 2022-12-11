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
    for(int t = 1; t <= tc; t ++ ){
        int n, m;
        cin >> n >> m;
        int sum = 0;
        int x;
        for(int i = 1; i <= n; i ++ ){
            cin >> x;
            sum += x;
        }
        if(sum == m){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}