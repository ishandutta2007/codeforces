#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e12

void open(){
    freopen("in.txt","r",stdin);
    //freopen("01.out","w",stdout);
}

main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int k;
    for(int j = 0;j<n;j++){
        cin >> k;
        if(j == n-1){
            for(int i = 1;i<k;i++){
                cout << "PLR";
            }
            if(k != 0)cout << "P";
        }
        else{
            for(int i = 1;i<k;i++){
                cout << "PRL";
            }
            if(k!=0)cout << "P";
            cout << "R";
        }
    }
    return 0;
}