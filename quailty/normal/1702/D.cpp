#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
char str[MAXN];
bool rem[MAXN];
int solve()
{
    int p,s=0;
    scanf("%s%d",str,&p);
    int n=strlen(str);
    vector<int> loc[26];
    for(int i=0;i<n;i++)
        loc[str[i]-'a'].push_back(i),s+=str[i]-'a'+1,rem[i]=1;
    for(int i=25;i>=0;i--)
        while(!loc[i].empty() && s>p)
            rem[loc[i].back()]=0,loc[i].pop_back(),s-=i+1;
    for(int i=0;i<n;i++)
        if(rem[i])printf("%c",str[i]);
    return 0*printf("\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}