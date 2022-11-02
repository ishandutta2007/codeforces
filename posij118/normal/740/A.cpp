// Example program
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, a, b, c, mini;
    cin >> n >> a >> b >> c;
    
    if(n%4==0) cout << "0";
    else if(n%4==3){
        mini=a;
        if(b+c<mini) mini=b+c;
        if(3*c<mini) mini=3*c;
        cout << mini;
    }
    
    else if(n%4==1){
        mini=c;
        if(b+a<mini) mini=b+a;
        if(3*a<mini) mini=3*a;
        cout << mini;
        
    }
    
    else {
        mini=b;
        if(2*a<mini) mini=2*a;
        if(2*c<mini) mini=2*c;
        cout << mini;
        
    }
  
}