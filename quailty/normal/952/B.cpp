#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(int i=0;i<10;)
    {
        cout<<i<<endl;
        string str;
        getline(cin,str);
        if(str=="cool")
        {
            cout<<"normal"<<endl;
            break;
        }
        if(str=="not bad")
        {
            cout<<"normal"<<endl;
            break;
        }
        if(str=="don't touch me")
        {
            cout<<"normal"<<endl;
            break;
        }
        if(str=="great")
        {
            cout<<"normal"<<endl;
            break;
        }
        if(str=="don't think so")
        {
            cout<<"normal"<<endl;
            break;
        }
        if(str=="go die in a hole")
        {
            cout<<"grumpy"<<endl;
            break;
        }
        if(str=="are you serious")
        {
            cout<<"grumpy"<<endl;
            break;
        }
        if(str=="don't even")
        {
            cout<<"grumpy"<<endl;
            break;
        }
        if(str=="worse")
        {
            cout<<"grumpy"<<endl;
            break;
        }
        if(str=="no way")
        {
            cout<<"grumpy"<<endl;
            break;
        }
        int res=0;
        for(int i=0;i<100000000;i++)
            res+=i*i;
        res/=res;
        i+=res;
    }
    return 0;
}