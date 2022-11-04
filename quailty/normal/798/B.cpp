#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=55;
string str[MAXN];
int cal(string now,string tar)
{
    for(int i=0;i<(int)now.size();i++)
    {
        if(now==tar)return i;
        now.push_back(now.front());
        now.erase(now.begin());
    }
    return MAXN*MAXN;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>str[i];
    int res=MAXN*MAXN;
    for(int i=0;i<(int)str[0].size();i++)
    {
        int now=i;
        for(int j=1;j<n;j++)
            now+=cal(str[j],str[0]);
        res=min(res,now);
        str[0].push_back(str[0].front());
        str[0].erase(str[0].begin());
    }
    return 0*printf("%d",(res<MAXN*MAXN ? res : -1));
}