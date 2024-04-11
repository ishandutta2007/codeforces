#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int cnt[6],res[MAXN];
vector<pair<int,int> >les[6];
int getId(char s[])
{
    if(s[0]=='S')return 0;
    if(s[0]=='M')return 1;
    if(s[0]=='L')return 2;
    if(s[1]=='L')return 3;
    if(s[2]=='L')return 4;
    if(s[3]=='L')return 5;
    return -1;
}
int main()
{
    for(int i=0;i<6;i++)
        scanf("%d",&cnt[i]);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[15];
        scanf("%s",s);
        int hes=0,id=getId(s);
        for(int i=0;s[i];i++)
            if(s[i]==',')hes=1;
        if(hes)les[id].push_back(make_pair(i,0));
        else res[i]=id,cnt[id]--;
    }
    for(int i=0;i<6;i++)
        if(cnt[i]<0)return 0*printf("NO");
    for(int i=0;i<6;i++)
    {
        while(les[i].size() && cnt[i])
        {
            res[les[i].back().first]=i;
            les[i].pop_back();
            cnt[i]--;
        }
        for(int j=0;j<(int)les[i].size();j++)
            if(les[i][j].second==1)return 0*printf("NO");
        while(les[i].size())
        {
            les[i+1].push_back(make_pair(les[i].back().first,1));
            les[i].pop_back();
        }
    }
    printf("YES\n");
    for(int i=0;i<n;i++,printf("\n"))
    {
        if(res[i]==0)printf("S");
        if(res[i]==1)printf("M");
        if(res[i]==2)printf("L");
        if(res[i]==3)printf("XL");
        if(res[i]==4)printf("XXL");
        if(res[i]==5)printf("XXXL");
    }
    return 0;
}