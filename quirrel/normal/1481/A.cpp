#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        string s;
        cin >>x>>y>>s;
        int l=0,r=0,d=0,u=0;
        for(char i : s){
            if(i=='L') l++;
            if(i=='R') r++;
            if(i =='U') u++;
            if(i == 'D') d++;
        }
        if(x < 0) x = -x, swap(l,r);
        if(y < 0) y = -y, swap(d,u);
        if(r >= x && u >= y) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}