#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int i=0;
    int j=0;
    int res=0;
    while (j<n){
        if (v[j]-v[i]<=5){
            res=max(res,j-i+1);
            j++;
        } else i++;
    }
    cout<<res;
    return 0;
}