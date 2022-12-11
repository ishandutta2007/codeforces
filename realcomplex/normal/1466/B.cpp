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
    for(int t = 1; t <= tc; t ++ ){
        int n;
        cin >> n;
        vector<int> x(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> x[i];
        }
        int sol = 1;
        x[n-1]++;
        for(int i = n - 2; i >= 0 ; i -- ){
            if(x[i] + 1 < x[i + 1]){
                x[i]++;
                sol++;
            }
            else if(x[i] < x[i + 1]){
                sol ++ ;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}