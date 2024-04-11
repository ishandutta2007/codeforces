#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    string res=a+b.substr(0,1);
    for(int i=1;i<(int)a.size();i++)
        res=min(res,a.substr(0,i)+b.substr(0,1));
    cout<<res<<endl;
    return 0;
}