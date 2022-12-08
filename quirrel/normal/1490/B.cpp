#include<bits/stdc++.h>
using namespace std;
int a[100009];
main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        a[0] = 0, a[1] = 0, a[2] = 0;
        for(int i =1; i <= n; i++){
            int x;
            cin>>x;
            a[x%3]++;
        }
        int ans = 0;
        while(a[0] != n/3 || a[1] != n/3 || a[2] != n/3){
            if(a[0] > n/3) a[0]--, a[1]++,ans++;
            if(a[1] > n/3) a[1]--, a[2]++,ans++;
            if(a[2] > n/3) a[2]--, a[0]++,ans++;
        }
        cout<<ans<<endl;
    }


}