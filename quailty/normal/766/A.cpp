#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<(a==b ? -1 : (int)max(a.size(),b.size()))<<endl;
    return 0;
}