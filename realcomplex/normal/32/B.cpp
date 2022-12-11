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
    string s;
    cin >> s;
    int n = s.size();
    char k[n+1];
    for(int j = 0;j<n;j++){
        k[j] = s[j];
    }
    k[n] = '#';
    for(int i = 0;i<n;i++){
        if(k[i] == '.'){
            cout << 0;
        }
        else{
            if(k[i+1] == '-'){
                cout << 2;
                i++;
            }
            else{
                cout << 1;
                i++;
            }
        }
    }
    return 0;
}