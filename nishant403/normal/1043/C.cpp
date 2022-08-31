#include <bits/stdc++.h>
using namespace std;

int main()
{
string s;
    cin >> s;
    
    int i,j,ans=0;
    int f=0;
    
    for(i=0;i<s.length();i++) 
    {
        if(s[i]=='b' && (i!=s.length()-1 && s[i+1]=='a' )&& f==0) { cout << 1 <<  " "; f^=1; }
        
        else if(s[i]=='a' && ( i==s.length()-1 || s[i+1]=='b' ) && f==1) { cout << 1 << " " ; f^=1; }   
      
             else cout << 0 << " ";
        
    }
}