#include<bits/stdc++.h>
using namespace std;
const int MAXN=300005;
char str[MAXN];
int main()
{
    int n;
    scanf("%d%s",&n,str);
    queue<int> q;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')cnt++;
        else if(str[i]==')')cnt--;
        else str[i]=')',cnt--,q.push(i);
        while(cnt<(i<n-1))
        {
            if(!q.empty())
            {
                str[q.front()]='(';
                q.pop();
                cnt+=2;
            }
            else return 0*printf(":(\n");
        }
    }
    if(cnt==0)printf("%s\n",str);
    else printf(":(\n");
    return 0;
}