#include<bits/stdc++.h>

using namespace std;
long long L[200009],R[200009];
main(){
    long long t;
    cin >> t;
    while(t--){
        int n,l,r, ll = 0,rr= 0 ,lp = 0, rp = 0;
        cin >> n >> l >> r;
        for(int i =1; i <= l; i++){
            int c;
            cin >> c;
            L[c]++;
        }
        for(int i =1; i <= r; i++){
            int c;
            cin >> c;
            R[c]++;
        }
        int ans = 0;

        for(int i = 1; i <= n; i++){
            int d = min(L[i], R[i]);
            L[i] -= d;
            R[i] -= d;
            lp += L[i] / 2;
            rp += R[i] / 2;
            ll += L[i];
            rr += R[i];
            L[i] = 0; R[i] = 0;
        }
        if(ll > rr){
            swap(ll, rr);
            swap(lp, rp);
        }
        int d = min((rr - ll)/2, rp);
        ans += d;
        rp -= d;
        rr -= 2*d;
        d = min(lp, rp);
        ans += 2*d;
        rr -= 2*d;
        ll -= 2*d;
        cout << ans + abs(rr -ll)/2 + (ll+rr)/2<<endl;


    }
}