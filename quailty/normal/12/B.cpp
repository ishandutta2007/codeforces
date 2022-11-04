#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a,b;
int main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b;
    sort(a.begin(),a.end());
    if(a.size()>1)
    {
        int loc=0;
        while(loc<a.size() && a[loc]=='0')loc++;
        swap(a[0],a[loc]);
    }
    cout<<(a==b ? "OK" : "WRONG_ANSWER")<<endl;
    return 0;
}