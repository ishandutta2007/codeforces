#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second

int main(){

    int n;
    cin >> n;
    int sk;
    int f,o;
    f = 0;
    o = 0;
    for(int i = 0;i<n;i++){
        cin >> sk;
        if(sk == 5){
            f++;
        }
        else{
            o++;
        }
    }
    if(o == 0){
        cout << -1;
        return 0;
    }
    int am = 0;
    for(int i = 0;i<(f/9)*9;i++){
        cout << 5;
        am = 1;
    }
    if(am == 0){
        if(o >= 1){
            cout << 0;
        }
        else{
            cout << -1;
        }
        return 0;
    }
    for(int i = 0;i<o;i++){
        cout << 0;
    }

    return 0;
}