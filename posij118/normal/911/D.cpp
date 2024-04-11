#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, l, r;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    bool x=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[j]<a[i]) x^=1;
        }
    }
    cin >> m;

    for(int i=0; i<m; i++){
        cin >> l >> r;
        for(int j=l-1; j<l-1+(r+1-l)/2; j++){
            swap(a[j], a[r+l-j-2]);
            x^=1;
        }

        if(x==0) cout << "even" << endl;
        else cout << "odd" << endl;
    }
}