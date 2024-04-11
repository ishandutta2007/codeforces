#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        long long n;
        long long k;
        cin >> n >> k;
        if(n <= 61 && k > (1ll << (n-1))) {cout<<-1<<endl; continue;}
        k--;
        ll j = 1;
        for(ll i = 2; i <= n; i++){
            if(n - i > 60 || !(k & (1ll<<(n-i)))){
                for(ll k = i-1; k >= j; k--)
                    cout << k <<" ";
                j = i;
            }
        }
        for(ll k = n; k >= j; k--)
            cout << k <<" ";
        cout<<endl;
    }

}
/*

*/