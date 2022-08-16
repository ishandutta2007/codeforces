#include <bits/stdc++.h>
using namespace std;

#define f(n) for(i=0;i<n;i++)

int main()
{
    int n,k,m,i,x=0,t1,t2;
    cin >> n >> m >> k >> t1;
    int a[n];
    f(n-1){  cin >> t2; a[i]=t2-t1-1; t1=t2; }
    
    sort(a,a+n-1);
    
    f(n-k) x+=a[i];
    cout << x+n;
     
    
    
}