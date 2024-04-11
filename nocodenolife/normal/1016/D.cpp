#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll n,m;
    cin>>n>>m;
    
    ll row[n];
    ll col[m];
    
    ll row_xor = 0;
    for(ll i=0;i<n;i++){
        cin>>row[i];
        row_xor = row_xor^row[i];
    }
    
    ll col_xor = 0;
    for(ll i=0;i<m;i++){
        cin>>col[i];
        col_xor = col_xor^col[i];
    }
    
    if(row_xor!=col_xor)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(i<n-1 && j<m-1)
            {
                cout<<"0 ";
                continue;
            }
            if(i!=n-1 && j==m-1)
            {
                cout<<row[i]<<" ";
                continue;
            }
            if(i==n-1 && j!=m-1)
            {
                cout<<col[j]<<" ";
                continue;
            }
            else
            {
                ll printed = row_xor ^ row[i] ^ col[j];
                cout<<printed<<" ";
                continue;
            }
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}