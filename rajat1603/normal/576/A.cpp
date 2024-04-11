#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
set < pair < int , int > > s;
int n;
int pr[N];
int main(){
    int cur = 0;
    cin >> n;
    for(int i = 2 ; i <= n ; ++i){
        bool b = 1;
        for(int j = 2 ; j * j <= i ; ++j){
            if(i % j == 0){
                b = 0;
                break;
            }
        }
        if(b){
            pr[++cur] = i;
        }
    }
    int ss = 0;
    for(int i = 1 ; i <= cur ; ++i){
        int temp = pr[i];
        while(temp <= n){
            s.insert(make_pair(++ss , temp));
            temp *= pr[i];
        }
    }
    cout << s.size() << endl;
    for(auto x : s){
        cout << x.second << " ";
    }
}