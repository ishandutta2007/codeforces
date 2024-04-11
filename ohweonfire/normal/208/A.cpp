#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a,b;
    cin>>a;
    int c;
    c=a.find("WUB");
    while(c!=-1)
    {
        a.replace(c,3," ");
        c=a.find("WUB");
    }
    while(a.substr(0,1)==" ")
    a.replace(0,1,"");
    while(a.substr(a.size()-1,1)==" ")
    a.replace(a.size()-1,1,"");
    cout<<a;
    return 0;
}