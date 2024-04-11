#include <iostream>
#include <vector>
#include <algorithm>
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
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        int res = -1;
        vector<int> a(n); 
        for(int i = 0; i < n; i ++ ){
            cin >> a[i];
            if(res == -1 || a[i] > a[res]){
                res = i;
            }
        }
        cout << res + 1 << "\n";
    }
    return 0;
}