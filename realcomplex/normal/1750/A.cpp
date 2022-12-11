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
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        int f;
        int a;
        for(int i = 1; i <= n; i ++ ){
            cin >> a;
            if(i == 1) f = a;
        }
        if(f == 1){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}