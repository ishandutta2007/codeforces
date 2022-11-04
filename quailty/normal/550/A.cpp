#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
char s[100005];
vector<int>ab,ba;
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len-1;i++)
    {
        if(s[i]=='A'&&s[i+1]=='B')ab.push_back(i);
        if(s[i]=='B'&&s[i+1]=='A')ba.push_back(i);
    }
    if(ab.empty() || ba.empty())printf("NO\n");
    else
    {
        if(ab[0]+1<ba[ba.size()-1])printf("YES\n");
        else if(ba[0]+1<ab[ab.size()-1])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}