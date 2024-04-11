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
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<int> c(n);
        int has = -1;
        for(int i = 0; i < n; i ++ ){
            cin >> c[i];
        }
        for(int i = 0 ; i < n; i ++ ){
            if(c[i] == 1){
                has = i;
            }
        }
        int pv;
        int nw;
        if(has == -1){
            cout << "No\n";
        }
        else{
            pv = has;
            nw = (has + 1) % n;
            bool valid = true;
            for(int j = 1; j < n; j ++ ){
                if(c[nw] > c[pv]){
                    if(c[nw] != c[pv] + 1) valid = false;
                }
                else{
                    if(c[nw] == 1) valid = false;
                }
                pv ++ ;
                nw ++ ;
                if(pv == n) pv = 0;
                if(nw == n) nw = 0;
            }
            if(valid){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }
    return 0;
}