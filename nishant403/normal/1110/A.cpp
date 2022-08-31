#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int b,k;
    cin >> b >> k;
    
    
    int i,temp[k],value=1;
    int ans=0;
    for(i=0;i<k;i++)
        cin >> temp[i];    
        
    for(i=k-1;i>=0;i--) 
    {
        
        ans=(ans+(value*temp[i]))%2;
        value=(value*b)%2;
            }
    if(ans%2==1) cout << "odd";
    else cout << "even";
    
    
    return 0;
}