#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long
#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

signed main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    string forc = "CODEFORCES";
    if(s.size()<=forc.size()){
        cout << "NO";
        exit(0);
    }
    string k;
    for(int i = 0;i<s.size();i++){
        for(int j = 0;j<=s.size();j++){
            k = s;
            k.erase(i,j);
            if(k == forc){
                cout << "YES";
                exit(0);
            }
        }
    }
    cout << "NO";
    return 0;
}