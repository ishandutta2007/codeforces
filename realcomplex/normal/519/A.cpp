#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char,int>s;
    s['q'] = 9;
    s['r'] = 5;
    s['b'] = 3;
    s['n'] = 3;
    s['p'] = 1;
    s['k'] = 0;
    int sum = 0;
    int sum1 = 0;
    char k;
    for(int i = 0;i<8;i++){
        for(int x = 0;x<8;x++){
            cin >> k;
            if(k != '.'){
                if(k >= 65 && k <= 90 ){
                    sum += s[k+32];
                }
                else{
                    sum1 += s[k];
                }
            }
        }
    }
    if(sum == sum1){
        cout << "Draw";
    }
    else if(sum < sum1){
        cout << "Black";
    }
    else{
        cout << "White";
    }
    return 0;
}