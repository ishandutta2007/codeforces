#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[109];
main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        a[0] = -1;
        int ok = 1;
       for(int i = 1; i <= n; i++){
        cin >> a[i];

        }
        for(int i = 1; i <= n; i++){
        if(a[i] <= a[i-1]) ok = 0;
        a[i+1]+=a[i]-a[i-1]-1;
        a[i] = a[i-1]+1;
       }
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}