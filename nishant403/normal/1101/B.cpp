#include <bits/stdc++.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

string s;
cin >> s;
///first we will find [ and : from start and then from end
//

int key1=1;
int firstcolon=-1;
int secondcolon=-1;
int i;
for( i=0;i<s.size();i++)
{
if(s[i]=='[' && key1)
{
 key1=0;   
}
if(s[i]==':' && key1==0)
{
    firstcolon=i;
    break;
}
}
key1=1;
for(i=s.size()-1;i>=0;i--)
{
if(s[i]==']' && key1)    key1=0;

if(s[i]==':' && key1==0 )
{
    secondcolon=i;
    break;
}
    
    
}
int count=4;

if(firstcolon==-1 || secondcolon==-1 || firstcolon >= secondcolon) cout << "-1";
else
{
for(i=firstcolon+1;i<=secondcolon-1;i++)    
if(s[i]=='|')count++;

    
cout << count;
    
}


return 0;
}