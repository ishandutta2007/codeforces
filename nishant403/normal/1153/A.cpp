#include <iostream>
using namespace std;

int main()
{
 int n,k,ans=999999999,r=0;
    
 cin >> n >> k;
  int l,d;  
    for(int i=0;i<n;i++)
    {
    cin >> l >> d;
        if(l >= k) { if(ans > l-k) ans = l-k, r= i+1; }      
    else if( (l-k)+((k-l-1)/d + 1)*d < ans) ans=(l-k)+((k-l-1)/d + 1)*d,r=i+1;    
    }
    cout << r;
}