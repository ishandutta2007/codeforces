#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a.length()>10) {cout<<a[0]; cout<<a.length()-2; cout<<a[a.length()-1]; cout<<endl;}
        else cout<<a<<endl;
    }
    return 0;
}