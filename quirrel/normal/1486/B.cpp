#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[1009],y[1009];
main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i =1; i <= n; i++){
            cin >> x[i]>>y[i];
        }
        sort(x+1,x+n+1);
        sort(y+1,y+n+1);
        if(n % 2 == 1) cout<<1<<endl;
        else cout <<(x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1)<<endl;
    }

}