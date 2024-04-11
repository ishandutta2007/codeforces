#include <iostream>   
using namespace std;
typedef long long ll;

ll n,x,t1;   
ll a[1000005];  
  
int main()  
{  
    ll ct = 0;  
    cin >> n >> x;  
    for(int i=1;i<=n;i++)  
    {  
        cin >> t1;  
        ll t = t1^x;  
        ct += a[t];  
        a[t1]++;  
    }  
    cout << ct <<endl;  
    return 0;   
}