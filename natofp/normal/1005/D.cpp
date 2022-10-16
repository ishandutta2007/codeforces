#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin>>s;
    int w=0;
    int a=0; int b=0;
    for(int i=0;i<s.length();i++)
    {

        if((s[i]-48)%3==0)
        {

            a=0; b=0; w++;
        }
        else if((s[i]-48)%3==1)
        {

            a++;
            if(a==3 || (a>=1 && b>=1))
            {
                w++; a=0; b=0;

            }
        }
        else if((s[i]-48)%3==2)
        {

            b++;
            if(b==3 || (a>=1 && b>=1))
            {

                w++; a=0; b=0;
            }
        }
    }
    
   cout<<max(0,w);
    return 0;
}