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
    int q;
    cin >> q;
    ll u, v;
    for(int t = 1; t <= q; t ++ ){
        cin >> u >> v;
        if(u > v){
            cout << "No\n";
        }
        else{
            int cnt = 0;
            for(int i = 0 ; i < 30 ;i ++ ){
                if((u & (1 << i))){
                    cnt ++ ;
                }
                if((v & (1 << i))){
                    cnt -- ;
                    if(cnt < 0){
                        break;
                    }
                }
            }
            if(cnt == -1){
                cout << "No\n";
            }
            else{
                cout << "Yes\n";
            }
        }
    }
    return 0;
}