#include "bits/stdc++.h"
using namespace std;
int n;
string temp;
int res = 0;
int main(){
    cin >> n;
    while(n--){
        cin >> temp;
        for(int i = 0 ; i < temp.size() ; ++i){
            if(temp[i] == '+'){
                res++;
                break;
            }
            if(temp[i] == '-'){
                res--;
                break;
            }
        }
    }
    cout << res;
}