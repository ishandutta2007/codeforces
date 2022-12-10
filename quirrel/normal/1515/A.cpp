#include<bits/stdc++.h>
using namespace std;
int a[1009];
main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int s = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s += a[i];
        }
        sort(a+1, a+n+1);
        if(s == x) cout<<"NO"<<endl;
        else {cout<<"YES"<<endl;
            s = 0;
            for(int i = 1; i <= n; i++){
                s += a[i];
                if(s == x) {swap(a[i], a[i+1]); break;}
            }
            for(int i= 1; i <= n; i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
    }
}