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
    string a;
    cin >> a;
    int n;
    cin >> n;
    string k[n];
    for(int i = 0;i<n;i++){
        cin >> k[i];
        if(k[i] == a){
            cout << "YES";
            exit(0);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(k[i][1] == a[0] && k[j][0] == a[1]){
                cout << "YES";
                exit(0);
            }
        }
    }
    cout << "NO";
    return 0;
}