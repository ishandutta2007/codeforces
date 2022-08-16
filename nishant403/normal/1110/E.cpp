#include <bits/stdc++.h>
using namespace std;
#define f(n) for(i=0;i<n;i++)


int main()
{
 int n,i;
 cin >> n;
 
 int a[n],b[n];
 f(n) cin >> a[i];
 f(n) cin >> b[i];
 
 
 if(a[0]!=b[0] || a[n-1] != b[n-1])
    cout << "No";
 
else
{
 f(n-1) a[i]=a[i+1]-a[i];
 f(n-1) b[i]=b[i+1]-b[i];
 
 sort(a,a+n-1);
 sort(b,b+n-1);
 
 if( equal(a,a+n-1,b)) cout << "Yes";
 else cout << "No";
 
}
}