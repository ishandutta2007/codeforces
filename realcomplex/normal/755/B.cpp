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
    unordered_map<string,int>k;
    int n,m;
    cin >> n >> m;
    int b = 0;
    string s;
    for(int j = 0;j<n+m;j++){
        cin >> s;
        k[s]++;
        if(k[s] > 1){
            b++;
        }
    }
    if(b%2 == 1){
        if(n>=m){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
    }
    else{
        if(n>m) cout << "YES";
        else cout << "NO";
    }
    return 0;
}