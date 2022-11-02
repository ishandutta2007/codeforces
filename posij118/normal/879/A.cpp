#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y, z;
    cin >> n;
    int s[n];
    int d[n];

    for(int i=0; i<n; i++){
        cin >> s[i] >> d[i];
    }

    int da, da2;
    da=0;
    for(int i=0; i<n; i++){
        if(s[i]>da) da=s[i];
        else{
            x=da/d[i];
            y=d[i]*x+s[i]+d[i];
            while(y>da){
                da2=y;
                y-=d[i];
            }
            da=da2;
        }
    }

    cout << da;

}