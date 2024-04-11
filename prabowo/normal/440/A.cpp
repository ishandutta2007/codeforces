#include<bits/stdc++.h>
using namespace std;

int main(){
    long n,t;
    cin >> n;
    bool e[100001]={};
    for (long i=0; i<n-1; i++){
        cin >> t;
        e[t] = true;
    }
    for(long i=1; i<=n; i++) if (!e[i]) {cout << i << endl; break;}

}