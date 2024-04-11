#include<bits/stdc++.h>
using namespace std;

int main(){
    int y;
    cin >> y;
    while(1){
        y++;
        int a = y%10, b=y%100/10, c=y%1000/100, d=y%10000/1000;
        if (a != b && a != c && a != d && b != c && b != d && c != d){
            cout << y << endl;
            break;
        }
    }
    return 0;
}