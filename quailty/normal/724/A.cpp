#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string day[7]={ "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int cnt[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline int getId(string s)
{
    for(int i=0;i<7;i++)
        if(s==day[i])return i;
    return -1;
}
int main()
{
    string a,b;
    cin>>a>>b;
    int ta=getId(a),tb=getId(b);
    for(int i=0;i<11;i++)
        if((ta+cnt[i])%7==tb)return 0*printf("YES");
    return 0*printf("NO");
}