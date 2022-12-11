#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}


int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    if(n>=m){
        cout << n+m-1 << "\n";
        for(int j = 1;j<=n;j++){
            cout << j << " " << 1 << "\n";
        }
        for(int i = 2;i<=m;i++){
            cout << 1 << " " << i << "\n";
        }
    }
    else{
        cout << n+m-1 << "\n";
        for(int j = 1;j<=m;j++){
            cout << 1 << " " << j << "\n";
        }
        for(int i = 2;i<=n;i++){
            cout << i << " " << 1 << "\n";
        }
    }
    return 0;
}