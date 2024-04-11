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
    int n;
    cin >> n;
    if(n<4){
        cout << "NO";
        exit(0);
    }
    cout << "YES\n";
    if(n%2==0){
        cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
        for(int j = 6;j<=n;j+=2){
            cout << j << " - " << j-1 << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
    }
    else{
        cout << "5 * 4 = 20\n20 + 3 = 23\n2 - 1 = 1\n23 + 1 = 24\n";
        for(int j = 7;j<=n;j+=2){
            cout << j << " - " << j-1 << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
    }
    return 0;
}