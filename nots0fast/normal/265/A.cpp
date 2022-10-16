#include <iostream>
#include <string>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
int main()
{
    string a,b;
    cin>>a>>b;
    int index = 0;
    fori(b.length())
    {
        if(index<a.length() && b[i] == a[index])
        {
            ++index;
        }
    }
    cout<<index+1;
}