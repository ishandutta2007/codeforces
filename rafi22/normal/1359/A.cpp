#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        if(n/k>=m)
            cout<<min(m,n/k)<<endl;
        else if((m-min(m,n/k))%(k-1)==0) cout<<min(m,n/k)-(m-min(m,n/k))/(k-1)<<endl;
        else cout<<min(m,n/k)-(m-min(m,n/k))/(k-1)-1<<endl;
    }



    return 0;
}