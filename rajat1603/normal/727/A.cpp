#include "bits/stdc++.h"
using namespace std;
vector < int > ans;
int a , b;
int main(){
    cin >> a >> b;
    ans.clear();
    ans.emplace_back(b);
    while(b > a){
        if(b & 1){
            if(b % 10 == 1){
                b /= 10;
            }
            else{
                cout << "NO\n";
                return 0;
            }
        }
        else{
            b >>= 1;
        }
        ans.emplace_back(b);
    }
    if(b < a){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    printf("%d\n" , int(ans.size()));
    reverse(ans.begin() , ans.end());
    for(int it : ans){
        cout << it << " ";
    }
}