#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string a;
string b;
int n;
void sorta(int l , int sz){
    if(!(sz & 1)){
        sz >>= 1;
        sorta(l , sz);
        sorta(l + sz , sz);
        for(int i = l ; i < l + sz ; ++i){
            if(a[i] < a[i + sz]){
                return;
            }
            if(a[i] > a[i + sz]){
                break;
            }
        }
        for(int i = l ; i < l + sz ; ++i){
            swap(a[i] , a[i + sz]);
        }
    }
}
void sortb(int l , int sz){
    if(!(sz & 1)){
        sz >>= 1;
        sortb(l , sz);
        sortb(l + sz , sz);
        for(int i = l ; i < l + sz ; ++i){
            if(b[i] < b[i + sz]){
                return;
            }
            if(b[i] > b[i + sz]){
                break;
            }
        }
        for(int i = l ; i < l + sz ; ++i){
            swap(b[i] , b[i + sz]);
        }
    }
}
int main(){
    cin >> a;
    cin >> b;
    n = a.size();
    a = " " + a;
    b = " " + b;
    sorta(1 , n);
    sortb(1 , n);
    if(a == b){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}