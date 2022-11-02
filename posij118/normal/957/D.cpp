#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, ans;
    ans=0;
    cin >> n;

    int a[n];
    int mi[n];
    int mi2[n];

    int siz[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
        if(i==0) mi[0]=a[0] + 1;
        else mi[i]=max(a[i] + 1, mi[i-1]);
    }

    mi2[n-1]=a[n-1] + 1;
    for(int i=n-2; i>=0; i--){
        mi2[i]=max(mi2[i+1] - 1, a[i] + 1);
    }

    for(int i=0; i<n; i++){
        siz[i]=max(mi[i], mi2[i]);
    }

    for(int i=0; i<n; i++){
        ans+=siz[i]-a[i]-1;
    }

    cout << ans;
}