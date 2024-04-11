
#include <iostream>

using namespace std;
char k,m1,d1,m2,d2,j;

int main() {
    cin>>k>>d1>>m1>>d2>>m2;
    if (d1=='T') d1=(char)'9'+1; else if (d1=='J') d1=(char)'9'+2; else
        if (d1=='Q') d1=(char) '9'+3; else if (d1=='K') d1=(char)'9'+4;
        else if (d1=='A') d1=(char)'9'+5;
        
    if (d2=='T') d2=(char)'9'+1; else if (d2=='J') d2=(char)'9'+2; else
        if (d2=='Q') d2=(char) '9'+3; else if (d2=='K') d2=(char)'9'+4;
        else if (d2=='A') d2=(char)'9'+5;    
    
    if (m1==m2) 
        if (d1>d2) cout<<"YES"; else cout<<"NO";
    else if (m1==k) cout<<"YES"; else cout<<"NO";
    return 0;
}