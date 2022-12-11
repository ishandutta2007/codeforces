#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int X[100005];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        int a = 1, b = 1;
        for(int i = 1; i <= n; i ++ ){
            cin >> X[i];
            if(X[i] < X[a]){
                a = i;
            }
            if(X[i] > X[b]){
                b = i;
            }
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}