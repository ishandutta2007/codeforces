#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)

int main()
{
map<string ,string> cat;
    
string a="normal",b="grumpy";    
string s;    
cat["no way"]=b;
cat["terrible"]=b;
cat["worse"]=b;
cat["are you serious"]=b;
cat["go die in a hole"]=b;
cat["don't even"]=b;
cat["not bad"]=a;
cat["cool"]=a;
cat["great"]=a;
cat["don't think so"]=a;
cat["don't touch me"]=a;
   
int i;
    
  f(i,10)
  {
   cout << i << "\n";
 
   getline(cin,s);
 
 if(cat.find(s)==cat.end() ) continue;
 else 
 { 
     cout << cat[s] << "\n"; 
     return 0; }
 }
    
    
}