#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[1000001];
int main()
{
    int b,k;cin>>b>>k;
    int sum=0;
    for (int i=0;i<k;i++) {
            cin>>a[i];
            sum+=a[i];
    }
    if (b%2){
        if (sum%2) cout<<"odd";
        else cout<<"even";
    } else {
         if (a[k-1]%2) cout<<"odd";
         else cout<<"even";
    }
    return 0;
}