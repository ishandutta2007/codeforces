#include <iostream>

using namespace std;

string x(string a,int d)
{
    string zamien="";
    for(int i=d-1;i>=0;i--)
        zamien+=a[i];
    for(int i=0;i<d;i++)
        a[i]=zamien[i];
    return a;
}

int main()
{
    string s;
    int n;
    cin>>n;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            s=x(s,i);
        }
    }
    cout<<s;
    return 0;
}