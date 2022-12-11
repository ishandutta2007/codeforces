#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);
    string n;
    cin >> n;
    string sk[10];
    for(int j = 0;j<10;j++){
        cin >> sk[j];
    }
    for(int x = 0;x<=n.size()-10;x+=10){
        for(int y = 0;y<10;y++){
            if(n.substr(x,10) == sk[y]){
                cout << y;
                break;
            }
        }
    }
    return 0;
}