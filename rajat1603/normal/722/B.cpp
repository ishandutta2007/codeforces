#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
int arr[N];
string str[N];
map < char , int > mp;
int main(){
    mp.clear();
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    cin.ignore();
    for(int i = 1 ; i <= n ; ++i){
        getline(cin , str[i]);
    }
    mp['a'] = 1;
    mp['e'] = 1;
    mp['i'] = 1;
    mp['o'] = 1;
    mp['u'] = 1;
    mp['y'] = 1;
    for(int i = 1 ; i <= n ; ++i){
        for(char c : str[i]){
            arr[i] -= mp[c];
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}