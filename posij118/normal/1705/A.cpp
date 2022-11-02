#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, x;
        cin >> n >> x;
        
        int h[2*n];
        
        for(int i = 0; i<2*n; i++){
            cin >> h[i];    
        }
        
        sort(h, h + 2*n);
        
        for(int i = 0; i<n; i++){
            if(h[i] + x > h[i+n]){
                cout << "NO" << endl;
                break;
            }    
            
            if(i == n - 1) cout << "YES" << endl;
        }
    }
}