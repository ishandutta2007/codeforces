
#include <iostream>
using namespace std;
int main()
{
int n,i,c=0,a=0;
    int d=0;
    
    cin >> n;
  
    for(int j=0;j<n;j++)
    { cin >> i;
     if(i>0) c++;
     else if(i<0) d++;
    }
    
   
    n+=(n&1);
    
    if(c >= n/2 ) cout << "1";
    else if(d >= n/2) cout << "-1";
        else cout <<"0";

}