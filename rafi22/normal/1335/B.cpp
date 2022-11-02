#include <iostream>

using namespace std;

int main()
{
    int t,a,n,b;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a>>n>>b;
        int it=0;
        string str="";
        for(int j=0;j<b;j++) str+=(char)(97+j);
        for(int j=0;j<a;j++) cout<<str[j%b];
        cout<<endl;

    }
    return 0;
}