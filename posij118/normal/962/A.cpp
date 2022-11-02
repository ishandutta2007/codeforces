#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, cur;
    double sum;
    cur=0;
    sum=0.0;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum+=a[i];
    }

    for(int i=0; i<n; i++){
        cur+=a[i];
        if(cur >= sum/2){
            cout << i+1;
            return 0;
        }
    }
}