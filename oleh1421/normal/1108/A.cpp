#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    int q;cin>>q;
    while (q--){
        int l1,l2,r1,r2;cin>>l1>>r1>>l2>>r2;
        if (l1!=r2) cout<<l1<<" "<<r2<<'\n';
        else cout<<r1<<" "<<l2<<'\n';

    }
    return 0;
}