#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)

void by()
{
 cout << ":(";
  exit(0);
}

int main()
{
    int i,j,k,n,m,h;
    string s;

    cin >> n;
    cin >> s;
    
    if(n&1) by();
    
    int op = (n/2);
    int cl= (n/2);
    int su=0;
    
    f(i,n) if(s[i]=='(') op--;
            else if(s[i]==')') cl--;
    
if(cl< 0 || op < 0 ) by();
    
    f(i,n)
    {
    if(s[i]=='(') su++;
    else if(s[i]==')') su--;
    else
    {
     if(op > 0) op--,s[i]='(',su++;
     else if(cl > 0 )cl--,s[i]=')',su--;
        else by();
    }  
        
     if(su<0) by();
     if(su==0 && i!=n-1) by();
      
    }
    
    cout << s;
}