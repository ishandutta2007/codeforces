#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;

string s[4];
int r[4];
int mulai[4];
int n,k;
int i;
int rhymetemp;
string x[3];
int tempat[3];
int rhymenow;

bool cekvokal(char c)
{
    return (c=='a' || c== 'e' || c=='i' || c=='o' || c=='u');
}
int countvk(string s)
{
    int cnt=0;
    int i;
    for (i=s.length()-1;i>=0;i--)
    {
        if (cekvokal(s[i]))
            cnt++;
        if (cnt==k)
            break;
    }
    if (cnt<k)
        return -1;
    return i;
}

bool checkrhyme(int a, int b)
{
    int i;
    bool sama=true;
    if (s[a].length()-mulai[a]!=s[b].length()-mulai[b])
        return false;
    else
    {
        for (i=1;i<=s[a].length()-mulai[a];i++)
            sama=sama&&(s[a][s[a].length()-i]==s[b][s[b].length()-i]);
        return sama;
    }
}
int carirhyme()
{
    int sudah=0;
    int i,j;
    for (i=0;i<4;i++)
    {
        mulai[i]=countvk(s[i]);
        if (mulai[i]==-1)
            return -1;
    }
    r[0]=1;
    sudah=1;
    tempat[1]=0;
    for (i=1;i<4;i++)
    {
        if (checkrhyme(i,tempat[1]))
        {
            r[i]=1;
        }
        else
        {
            if (sudah<2)
            {
                r[i]=2;
                tempat[2]=i;
                sudah=2;
            }
            else
            {
                if (checkrhyme(i,tempat[2]))
                    r[i]=2;
                else
                    return -1;
            }
        }
    }
    if (r[0]==1 && r[1]==1 && r[2]==1 && r[3]==1)
        return 0;
    else if (r[0]==1 && r[1]==1 && r[2]==2 && r[3]==2)
        return 1;
    else if (r[0]==1 && r[1]==2 && r[2]==1 && r[3]==2)
        return 2;
    else if (r[0]==1 && r[1]==2 && r[2]==2 && r[3]==1)
        return 3;
    else
        return -1;
    
}
int main()
{
    scanf("%d %d",&n,&k);
    for (i=0;i<n;i++)
    {
        cin >> s[0];
        cin >> s[1];
        cin >> s[2];
        cin >> s[3];
        rhymenow=carirhyme();
        if (rhymenow==1)
        {
            if (rhymetemp==0 || rhymetemp==1)
                rhymetemp=1;   
            else
                rhymenow=-1;
        }
        if (rhymenow==2)
        {
            if (rhymetemp==0 || rhymetemp==2)
                rhymetemp=2;
            else
                rhymenow=-1;
        }
        if (rhymenow==3)
        {
            if (rhymetemp==0 || rhymetemp==3)
                rhymetemp=3;
            else
                rhymenow=-1;
        }
        if (rhymenow==-1)
        {
            printf("NO\n");
            break;
        }
        
    }
    if (rhymenow!=-1)
    {
    if (rhymetemp==0)
        printf("aaaa\n");
    else if (rhymetemp==1)
        printf("aabb\n");
    else if (rhymetemp==2)
        printf("abab\n");
    else if (rhymetemp==3)
        printf("abba\n");
    }
}