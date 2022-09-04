#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,q[1000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>q[i];
    for(int k=0;k<n;k++){
        int f=0;
        for(int i=0;i<n;i++)
            if(q[i]!=i)
                f=1;
        if(f==0){
            cout<<"Yes";
            return 0;
        }
        for(int i=0;i<n;i++)
            if(i%2==0)
                q[i]=(q[i]+1)%n;
            else
                q[i]=q[i]==0?n-1:q[i]-1;
    }
    cout<<"No";
}