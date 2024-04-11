#include <iostream>

using namespace std;

int main()
{
    string x,y;
    cin >> x >> y;
    string z;
    bool var = true;
    for(int i = 0;i<x.size();i++){
        if(x[i] < y[i]){
            var = false;
            break;
        }
        else{
            z += y[i];
        }
    }
    if(var == true){
        cout << z;
    }
    else{
        cout << -1;
    }
    return 0;
}