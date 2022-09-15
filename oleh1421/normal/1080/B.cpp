#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long int l,r,q,a,k;
    cin>>q;
    long long int ans[q+1];
    for (int i=1;i<=q;i++){
        cin>>l>>r;
        if (l==r) {
            if (l%2==0) ans[i]=l;
            else ans[i]=-l;
        } else{
        a=0;
        if ((r-l)%2==0) {
            if (r%2==0) a=r;
            else a=-r;
            r--;
        }
        k=(r-l+1)/2;
        if (r%2==0) ans[i]=k;
        else ans[i]=-k;
        ans[i]+=a;
        }
    }
    for (int i=1;i<=q;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}