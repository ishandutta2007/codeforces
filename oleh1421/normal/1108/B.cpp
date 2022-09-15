#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<int>a;
    for (int i=0;i<n;i++) {
        int x;cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int d=a[n-1];
    for (int i=0;i<n-1;i++){
            vector<int>v;
            for (int k=1;k<=d;k++){
                if (a[i]%k==0) v.push_back(k);
                if (d%k==0) v.push_back(k);
            }
            sort(v.begin(),v.end());
            if (v==a) {
                cout<<d<<" "<<a[i];
                return 0;
            }
    }

    return 0;
}