#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e5

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}


main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    string k[n];
    for(int j = 0;j<n;j++){
        cin >> k[j];
    }
    set<string>has;
    for(int i = n-1;i>=0;i--){
        if(has.count(k[i]) == 0) cout << k[i] << "\n";
        has.insert(k[i]);
    }
    return 0;
}