#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
string u[10]={"01","10","10","11","11","10","11","11","10","01"};
string m[10]={"11","00","10","00","01","01","10","11","11","10"};
int main()
{
    string str,tu,tm;
    cin>>str;
    for(int i=0;i<(int)str.size();i++)
    {
        tu+=u[str[i]-'0'];
        tm+=m[str[i]-'0'];
    }
    string ru=tu,rm=tm;
    reverse(ru.begin(),ru.end());
    reverse(rm.begin(),rm.end());
    cout<<(tu==ru && tm==rm ? "Yes" : "No");
    return 0;
}