#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,r,x;
    cin>>n;
    int a[101],b[101];
    for (int i=0;i<=100;i++) a[i]=1;
    for (int i=0;i<n;i++){
        cin>>r;
        for (int i=0;i<=100;i++) b[i]=0;
        for (int i=0;i<r;i++){
            cin>>x;
            b[x]=1;
        }
        for (int i=1;i<=100;i++){
            a[i]=a[i]&b[i];
        }
    }
    for (int i=1;i<=100;i++) if (a[i]==1) cout<<i<<" ";
    return 0;
}