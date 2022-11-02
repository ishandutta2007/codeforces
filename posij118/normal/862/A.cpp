#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, cnt;
    cnt=0;
    cin >> n >> x;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]<x) cnt++;
        if(a[i]==x) cnt--;
    }

    cout << x-cnt;




}