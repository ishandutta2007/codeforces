#include <bits/stdc++.h>
using namespace std;

int main()
{
 string s1,s2;
    cin >> s1 >> s2;
    int m1=0,m2=0;
    
    m1=(s1[4]-'0') + 10*(s1[3]-'0')+60*(s1[1]-'0') + 600*(s1[0]-'0');
    
    m2=(s2[4]-'0') + 10*(s2[3]-'0')+60*(s2[1]-'0') + 600*(s2[0]-'0');
    
    int x=m2-m1;
    
    if( (m1+ x/2)/60 < 10) cout << 0;
    cout << (m1+ x/2 ) / 60 << ':' ;
     
    if((m1+x/2)%60 < 10)  cout << 0;
    cout << (m1 + x/2) %60;
    
    
    
    
    
    
}