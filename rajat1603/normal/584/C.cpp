#include "bits/stdc++.h"
using namespace std;
vector < int > positions;
int n , t , cur = 0;
string a , b , ans;
int main(){
    cin >> n >> t;
    cin >> a >> b;
    for(int i = 0 ; i < n ; ++i){
        if(a[i] != b[i]){
            positions.emplace_back(i);
        }
    }
    ans = a;
    int dif = positions.size();
    while(1){
        if(t >= dif){
            int remaining = t - dif;
            for(int j = cur ; j < positions.size() ; ++j){
                int i = positions[j];
                char x;
                for(x = 'a' ; x <= 'z' ; ++x){
                    if(x != a[i] && x != b[i]){
                        break;
                    }
                }
                ans[i] = x;
            }
            int y = 0;
            while(y < n && remaining){
                if(a[y] == b[y]){
                    ans[y] = (a[y] == 'a' ? 'b' : 'a');
                    --remaining;
                }
                ++y;
            }
            if(!remaining){
                cout << ans << endl;
            }
            else{
                cout << -1;
            }
            return 0;
        }
        else{
            if(cur >= positions.size() - 1){
                break;
            }
            int y = positions[cur];
            ans[y] = b[y];
            cur += 2;
            dif -= 2;
            --t;
        }
    }
    cout << "-1";
}