#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,k,m;
    double sum=0;
    cin >> n >> k >> m;
    int a[n];
    
    int i;
    for(i=0;i<n;i++) 
    {
        cin >> a[i];
        sum+=a[i];
    }
    
    double ans=0;
    sort(a,a+n);
    
   double countleft=n; 
    for(i=0;i<n-1;i++)
    {
        if(m<=0) break;
    
        if( (sum+m)/(countleft) <= (sum-a[i]+m-1)/(countleft-1))
        {
        	
            sum-=a[i];
            countleft--;
            m--;
            
        }
        else break;
        
        
    }

    if(m > countleft*k)
{
    sum+=countleft*k;
}
else 
{
    sum+=m;
}


    cout << fixed << setprecision(15) << (double)sum / countleft;
    return 0;
    }