#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int main()
{
    int w=0;
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.length()-1;i++)
    {
        if(a[i]=='0' && b[i]=='0' && b[i+1]=='0') {w++; a[i]='X'; b[i]='X'; b[i+1]='X';}
        else if(a[i]=='0' && b[i]=='0' && a[i+1]=='0') {w++; a[i]='X'; b[i]='X'; a[i+1]='X';}
        else if(a[i]=='0' && a[i+1]=='0' && b[i+1]=='0') {w++; a[i]='X'; a[i+1]='X'; b[i+1]='X';}
        else if(b[i]=='0' && a[i+1]=='0' && b[i+1]=='0') {w++; b[i]='X'; a[i+1]='X'; b[i+1]='X';}


    }
    cout<<w;
    return 0;
}