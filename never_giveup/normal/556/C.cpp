#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int ans=2*n-k;
    if(n==1 || k==1){
        cout<<0;
        return 0;
    }
    for(int it=0;it<k;it++){
        int j;
        cin>>j;
        int x=n-1,y,fir;
        cin>>y;
        fir=y;
        int r=j;
        for(int i=1;i<j;i++){
            x=y;
            cin>>y;
            if(x+1!=y && r==j)
                r=i;
        }
        if(fir==1)
            ans-=(r-1)*2;
    }
    cout<<ans-1;
}