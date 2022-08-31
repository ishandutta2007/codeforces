#include <bits/stdc++.h>
using namespace std;

int main()
{
int n,x,y;
cin >> n ;
int a[n];
int day = 1;    
    
    for(x=0;x<n;x++)cin >> a[x];
    sort(a,a+n);
    y = 0;
    
    for(int i=0;i<n;i++)
    {
     if(a[i] >= day ) day++;
    }
    
cout << day-1;
}