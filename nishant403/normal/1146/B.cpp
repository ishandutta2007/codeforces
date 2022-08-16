#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<long long,long long>
#define vl vector<long> 

void by()
{
 cout << ":(\n";
    exit(0);
}

int main()
{
 fast;   
 int k=0,n;   
 string s;   
 cin >> s;
    
 n=s.length();   
 for(auto z : s) if(z=='a') k++;   

 int left = (n-k);    
     
 if(left%2==1) by();    
 
 int a = n-1;
 int b = n-(left/2)-1;   
 int c = 0;
    
 while(c<(left/2) )
 {
     if(b<0 || a<k+(left/2) )  by(); 
     
     if(s[b]=='a') { b--;continue; } 
     
     if(s[a]==s[b]){ a--; b--; c++; continue; }
     else by();
     
 }  
   int i; 
  f( i,k+left/2) cout << s[i];  
}