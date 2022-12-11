#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    map<string,string>dict;
    int n,m;
    cin >> n >> m;
    string a,b;
    for(int j = 0;j<m;j++){
        cin >> a >> b;
        dict[a] = b;
    }
    string l1,l2;
    for(int j = 0;j<n;j++){
        cin >> l1;
        l2 = dict[l1];
        if(l1.size()<=l2.size()){
            cout << l1 << " ";
        }
        else{
            cout << l2 << " ";
        }
    }
    return 0;
}