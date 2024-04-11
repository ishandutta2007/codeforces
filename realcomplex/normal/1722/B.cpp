#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        for(char &x : a){
            if(x == 'G') x = 'B';
        }
        for(char &x : b){
            if(x == 'G') x = 'B';
        }
        if(a == b){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}