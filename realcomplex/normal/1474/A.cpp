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
        string b;
        cin >> b;
        int las = -1;
        int f;
        for(int i = 0; i < b.size(); i ++ ){
            f = b[i] - '0';
            for(int j = 1 ; j >= 0; j -- ){
                if(j + f != las){
                    las = j + f;
                    cout << j;
                    break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}