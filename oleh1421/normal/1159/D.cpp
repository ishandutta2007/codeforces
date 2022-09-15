#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int n,k;cin>>n>>k;
    if (k==1){
        cout<<1;
        for (int i=1;i<n;i++) cout<<0;
        return 0;
    }
    int x=(n-k)/2+1;
    for (int i=0;i<n;i++){
        cout<<(i%x>0);
    }

    return 0;
}