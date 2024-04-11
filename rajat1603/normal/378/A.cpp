#include "bits/stdc++.h"
using namespace std;
int a , b;
int x , y , z;
int main(){
    cin >> a >> b;
    for(int i = 1 ; i <= 6 ; ++i){
        int g = abs(i - a);
        int h = abs(i - b);
        if(g < h){
            ++x;
        }
        if(g == h){
            ++y;
        }
        if(g > h){
            ++z;
        }
    }
    cout << x << " " << y << " " << z << endl;
}