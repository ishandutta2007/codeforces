#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int n , k;
string str[N];
int arr[N];
vector < string > v;
int main(){
    cin >> n >> k;
    for(int i = 1 ; i <= n - k + 1 ; ++i){
        cin >> str[i];
    }
    v.clear();
    for(int i = 1 ; i <= n ; ++i){
        if(i <= 26){
            string str = "";
            str += char('A' + i - 1);
            v.emplace_back(str);
        }
        else{
            string str = "A";
            str += char('a' + i - 26);
            v.emplace_back(str);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        arr[i] = 0;
    }
    int idx;
    if(str[1] == "YES"){
        for(int i = 1 ; i <= k ; ++i){
            arr[i] = i;
        }
        idx = k + 1;
    }
    else{
        arr[1] = 1;
        arr[2] = 1;
        idx = 3;
        for(int i = 3 ; i <= k ; ++i){
            arr[i] = idx++;
        }
    }
    for(int i = k + 1 ; i <= n ; ++i){
        if(str[i - k + 1] == "YES"){
            arr[i] = idx++;
        }
        else{
            arr[i] = arr[i - k + 1];
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        cout << v[arr[i] - 1] << " \n"[i == n];
    }
}