#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int32_t main() {
    int n;cin>>n;
    while (n--){
        int b,p,f,h,c;cin>>b>>p>>f>>h>>c;
        int res=0;
        for (int i=0;i<=p && i+i<=b;i++){
            res=max(res,i*h+min((b-i-i)/2,f)*c);
        }
        cout<<res<<endl;
    }
    return 0;
}


///20075213641185