#include<bits/stdc++.h>
using namespace std;
int a[100009];
main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>a[1];
        int ans = 0;
        for(int i =2; i <= n; i++){
            cin >>a[i];
            int x = max(a[i], a[i-1]), y = min(a[i], a[i-1]);
            while(x > 2*y) ans++, y = 2*y;
        }
        cout<<ans<<endl;
    }


}