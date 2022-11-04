#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    vector<int>now,res;
    int n;
    cin>>n>>str;
    for(int i=0;i<n;i++)
        now.push_back(i);
    for(int i=n-1;i>=0;i--)
    {
        res.push_back(now[i/2]);
        now.erase(now.begin()+i/2);
    }
    now.resize(n);
    for(int i=0;i<n;i++)
        now[res[i]]=i;
    for(int i=0;i<n;i++)
        cout<<str[now[i]];
    return 0;
}