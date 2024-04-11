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
    map<pair<string,string> ,int>has;
    int n;
    cin >> n;
    pair<string,string>k;
    int cnt = 0;
    for(int j = 0;j<n;j++){
        cin >> k.fi >> k.se;
        if(has[k] == 0){
            cnt++;
            has[k]++;
        }
    }
    cout << cnt;
    return 0;
}