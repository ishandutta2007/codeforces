#include<bits/stdc++.h>
using namespace std;
int f[1009];
main(){
    int t;
    cin >> t;
    while(t--){
        int n,r,l,u,d;
        cin>>n>>u>>r>>d>>l;
        int ok = 0;
        for(int i = 0; i < 2; i++){
            if(i) u--,l--;
             for(int i = 0; i < 2; i++){
            if(i) d--,l--;
             for(int i = 0; i < 2; i++){
            if(i) u--,r--; for(int i = 0; i < 2; i++){
            if(i) d--,r--;
            if(l >= 0 && l <= n-2 &&
               r >= 0 && r <= n-2 &&
               d >= 0 && d <= n-2 &&
               u >= 0 && u <= n-2) ok  =1;

        }d++;r++;

        }u++;r++;

        }d++;l++;
        }
        if(ok) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }

}