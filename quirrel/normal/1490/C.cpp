#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll> M;
main(){
    for(long long i = 1; i <= 10000; i++){
        M[i*i*i] =i;
    }
    int t;
    cin>>t;
    while(t--){
        long long x;
        cin >> x;
        int ok = 0;
        for(long long i = 1; i*i*i<x; i++){
            if(M[x-i*i*i]) ok = 1;
        }
        if(ok) cout<<"Yes"<<endl; else cout<<"No"<<endl;
    }


}