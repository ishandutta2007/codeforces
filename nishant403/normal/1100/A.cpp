#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,k,i,j;
    cin >> n >> k;
    int a[n];
    int b[101][2]={0};
    int t1=0,t0=0;
    for(i=0;i<n;i++) 
    {
        
        cin >> a[i];
    if(a[i]==1) t1++;
    else t0++;
    
    if(a[i]==1) b[i%k][1]++;
    else  b[i%k][0]++;
    
    }
    int max=0;
    
    for(i=0;i<k;i++)
    {
        if(abs((t1-b[i][1])-(t0-b[i][0])) > max)
        max=abs((t1-b[i][1])-(t0-b[i][0]));
    }
    cout << max;
    
    return 0;
}