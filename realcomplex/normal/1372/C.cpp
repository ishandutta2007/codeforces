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
    for(int t = 0; t < tc; t ++ ){
        int n;
        cin >> n;
        int a;
        int fix = 0;
        vector<int> hsh;
        for(int i = 0 ; i < n; i ++ ){
            cin >> a;
            a -- ;
            if(a == i){
                fix ++ ;
                hsh.push_back(1);
            }
            else{
                hsh.push_back(0);
            }
        }
        if(fix == n)
            cout << 0 << "\n";
        else if(fix == 0){
            cout << 1 << "\n";
        }
        else{
            int pf = 0, sf = 0;
            for(int i = 0 ; i < hsh.size(); i ++ ){
                if(hsh[i] == 0){
                    break;
                }
                pf++;
            }
            for(int i = hsh.size() - 1; i >= 0 ; i -- ){
                if(hsh[i] == 0){
                    break;
                }
                sf ++ ;
            }
            if(pf + sf == fix){
                cout << 1 << "\n";
            }
            else{
                cout << 2 << "\n";
            }
        }
    }
    return 0;
}