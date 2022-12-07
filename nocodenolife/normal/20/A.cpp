#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;
    string k = "";

    char a = 'q';
    for(int i=0;i<s.length();i++)
    {
    	if(!(s[i]=='/'&& a=='/'))
    		k+= s[i];
    	a = s[i];
    }
    int f = k.length()-1;
    while(k[f] == '/')
    {
    	k[f] = ' ';
    	f--;
    }
    if(f==-1)
    {
    	cout<<"/\n";
    }
    else
    	cout<<k<<"\n";

    return 0;
}