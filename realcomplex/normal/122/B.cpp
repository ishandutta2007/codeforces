#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second

int f,s;

int main()
{
    char k;
    while(cin >> k){
        if(k == '7'){
            s++;
        }
        else if(k == '4'){
            f++;
        }
    }
    if(f == 0 && s == 0){
        cout << -1;
    }
    else if(f >= s){
        cout << 4;
    }
    else{
        cout << 7;
    }
    return 0;
}