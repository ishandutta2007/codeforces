#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200009];
int b[200009];
int s[200009];
main(){
    int n , k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int l = 1, r = n;
    while(l < r){
        int mid = (l + r+1)/2;
        for(int i = 1; i <= n; i++){
            if(a[i] >= mid) b[i] = 1;
            else b[i] = -1;
            s[i] = s[i-1] + b[i];
        }
        int M = n+1;
        int ok = 0;
        for(int i = k; i <= n; i++){
            M = min(M, s[i-k]);
            if(s[i] > M) ok = 1;
        }
        if(ok) l = mid;
        else r = mid-1;
    }
    cout<<l<<endl;
}