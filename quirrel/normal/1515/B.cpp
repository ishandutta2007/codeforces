#include<bits/stdc++.h>
using namespace std;
int a[1009];
main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n % 2){
            cout <<"NO"<<endl;
            continue;
        }
        n /= 2;
        if(sqrt(n) == (int)sqrt(n)){
            cout <<"YES"<<endl;
            continue;
        }
        if(n % 2){
            cout <<"NO"<<endl;
            continue;
        }
        n /= 2;
        if(sqrt(n) == (int)sqrt(n)){
            cout <<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
}