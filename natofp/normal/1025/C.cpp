#include <iostream>

using namespace std;

int main()
{
    string s;
   cin>>s;
    int w=1;
    int akt=1;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]!=s[i-1]) akt++;
        else
        {
            
            if(akt>w) w=akt;
            akt=1;
        }
    }

    if(akt>w) w=akt;
    int a,b;
    a=1; b=1;
    int i=1;
    while(i<s.length())
    {
        if(s[i]!=s[i-1]) {a++; i++;}
        else break;
    }
    i=s.length()-2;
    while(i>=0)
    {
        if(s[i]!=s[i+1]) {b++; i--;}
        else break;
    }
    if(s[0]!=s[s.length()-1]) {w=max(w,a+b);}
    int n=s.length();

    cout<<min(w,n);
    return 0;
}