#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
map<string,int>mp;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        if(!mp[str])mp[str]++,cout<<"OK"<<endl;
        else cout<<str<<mp[str]++<<endl;
    }
    return 0;
}