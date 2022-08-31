#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j;
    int n;
    cin >> n;
    int temp;
    vector <int> a;
    for( i=0;i<n;i++) 
    {cin >> temp;
     a.push_back(temp);
    }    
    sort(a.begin(),a.end());
    
    int c1,c2=0;
    c1=a[n-1];
    
    vector<int> div;
    for(i=1;i<=a[n-1];i++)
    {
        if(a[n-1]%i==0) div.push_back(i);
    }
    
    for(i=0;i<div.size();i++)
    {
    for(j=0;j<n;j++)
    {
        if(div[i]==a[j])
        { 
            a[j]=-1;
          break;   
        }
    }
        
        
    }
    
    
    
    for(i=0;i<n;i++)
    {
        if(a[i] > c2) c2=a[i];
    }
    
    cout << c1 << " " << c2;
    
    return 0;
}