#include <iostream>
#include <string>
using namespace std;
int main()
{
    long long r=0;
    string s;
    cin>>s;
    int e=0;
    for(int i=0;i<s.size();i++)if(s[i]=='^')e=i;
    for(int i=0;i<s.size();i++)if(s[i]!='=')r+=(e-i)*(s[i]-'0');
    if(r>0)cout<<"left";
    else if(r)cout<<"right";
    else cout<<"balance";
    return 0;
}