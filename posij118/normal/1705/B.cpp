#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        int a[n];
        int lst = 0;
        int cnt = 0;
        
        long long ans = 0;
        cin >> lst;
        ans += lst;
        if(lst) cnt = 1;
        
        for(int i = 1; i<n - 1; i++){
            cin >> a[i];
            if(a[i] == 0 && cnt) ans++;
            else ans += a[i];
            lst = a[i];
            
            if(a[i] > 0) cnt = 1;
        }
        
        cin >> lst;
        
        cout << ans << endl;
       
    }
}