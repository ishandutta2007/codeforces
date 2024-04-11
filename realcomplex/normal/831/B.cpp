/*
   .
#???????
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string a,b;
    cin >> a >> b;
    string k;
    cin >> k;
    for(int i = 0;i<k.size();i++){
        if(k[i] >= '0' && k[i] <= '9'){
            cout << k[i];
            continue;
        }
        if(k[i]>96){
            cout << b[a.find(k[i])];
        }
        else{
            k[i]+=32;
            cout << char(b[a.find(k[i])]-32);
        }
    }
    return 0;
}