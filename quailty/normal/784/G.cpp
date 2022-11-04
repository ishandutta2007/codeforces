#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int eval(const string &str)
{
    int res=0;
    for(int i=0,j=0,sgn=1;i<(int)str.size();i=j)
    {
        if(str[i]=='+')j++,sgn=1;
        else if(str[i]=='-')j++,sgn=-1;
        else
        {
            int now=0;
            for(;j<(int)str.size() && str[j]>='0' && str[j]<='9';j++)
                now=now*10+str[j]-'0';
            res+=now*sgn;
        }
    }
    return res;
}
int main()
{
    string str,ed="++++++++++++++++++++++++++++++++++++++++++++++++.";
    cin>>str;
    int res=eval(str);
    if(res==0)
    {
        cout<<ed<<endl;
        return 0;
    }
	bool flag=0;
	if(res/100)
    {
		int x=res/100;
		for(int i=0;i<x;i++)
            cout<<"+";
        cout<<endl<<ed<<endl<<">";
		res%=100,flag=1;
	}
	if(res/10 || flag)
    {
		int x=res/10;
		for(int i=0;i<x;i++)
            cout<<"+";
        cout<<endl<<ed<<endl<<">"<<endl;
		res%=10;
	}
	int x=res;
	for(int i=0;i<x;i++)
        cout<<"+";
    cout<<endl<<ed<<endl;
    return 0;
}