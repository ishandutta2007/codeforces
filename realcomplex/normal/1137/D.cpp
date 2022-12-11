#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    while(1){
        cout << "next 1 2" << endl;
        int k;
        cin >> k;
        string t;
        for(int p = 0 ; p < k ; p ++ ){
            cin >> t;
        }
        cout << "next 1" << endl;
        cin >> k;
        for(int p = 0; p < k ; p ++ )
            cin >> t;
        if(k == 2){
            break;
        }
    }
    while(1){
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        int k;
        cin >> k;
        string t;
        for(int p = 0 ; p < k; p ++ ){
            cin >> t;
        }
        if(k == 1){
            cout << "done" << endl;
            return 0;
        }
    }
    return 0;
}