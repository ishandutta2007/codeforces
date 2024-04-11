#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200009];
int b[200009];
main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a+1,a+n+1);
        int lo = 1, hi = n;
        while(lo < hi){
            int mid = (lo +hi)/2;
            ll x = a[mid];
            int ok = 1;
            for(int j = 1; j <= n; j++){
                if(j == mid) continue;
                if(a[j] > x){
                    ok = 0;
                    break;
                }
                x += a[j];
            }
            if(ok) hi = mid;
            else lo = mid+1;
        }

    cout << n - lo + 1 <<endl;
    for(int i =1 ; i <= n; i++){
        if(b[i] >= a[lo]) cout<<i<<" ";
            }
            cout<<endl;
    }


}