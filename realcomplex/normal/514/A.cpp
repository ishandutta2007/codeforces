#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main(){

    vector<int>k;
    char s;
    while(cin >> s){
        k.push_back(s-48);
    }
    for(int i = 0;i<k.size();i++){
        if(k[i] >= 5){
            k[i] = 9 - k[i];
        }
        if(i == 0 && k[i] == 0){
            k[i] = 9;
        }
    }
    for(int i = 0;i<k.size();i++){
        cout << k[i];
    }
    return 0;
}