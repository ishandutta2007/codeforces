#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
# include <iostream>
# include <stdio.h>
using namespace std;

char a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int x;cin>>x;
        a[i]=x;
    }
    int q;
    cin>>q;
    while (q--) {
        int l,r,a1,b1;cin>>l>>r>>a1>>b1;
        char x=a1;
        char y=b1;
        if (l==0) return 1;
        for (int i = l-1; i < r; i++) {
            a[i] = (a[i] == x ? y : a[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout<<int(a[i])<<" ";
    }
}