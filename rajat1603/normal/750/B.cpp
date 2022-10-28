#include "bits/stdc++.h"
using namespace std;
int n;
int val;
long long x;
long long y;
string str;
void rekt(){
    cout << "NO\n";
    exit(0);
}
int main(){
    cin >> n;
    x = 0;
    y = 0;
    while(n--){
        cin >> val >> str;
        if(x == 0){
            if(str != "South"){
                rekt();
            }
        }
        if(x == 20000){
            if(str != "North"){
                rekt();
            }
        }
        if(str == "South"){
            x += val;
        }
        else if(str == "North"){
            x -= val;
        }
        else if(str == "East"){
            y += val;
        }
        else{
            y -= val;
        }
        if(x < 0){
            rekt();
        }
        if(x > 20000){
            rekt();
        }
    }
    if(x == 0){
        printf("YES\n");
    }
    else{
        rekt();
    }
}