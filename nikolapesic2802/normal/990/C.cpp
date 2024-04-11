#include <bits/stdc++.h>

using namespace std;
int nega[300001];
int main()
{
    int n;
    scanf("%i",&n);
    string s[n];
    for(int i=0;i<n;i++)
    {
        char seq[300001];
        scanf("%s",seq);
        s[i]=seq;
    }
    int poss[n]={};
    int negg[n]={};
    for(int i=0;i<n;i++)
    {
        int neg=0;
        int pos=0;
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]==')')
            {
                if(pos==0)
                {
                    neg++;
                }
                else
                {
                    pos--;
                }
            }
            else
            {
                pos++;
            }
        }
        if(pos==0)
        {
            nega[neg]++;
        }
        poss[i]=pos;
        negg[i]=neg;
    }
    long long res=0;
    for(int i=0;i<n;i++)
    {
        if(negg[i]==0)
        {
            res+=nega[poss[i]];
        }
    }
    printf("%I64d\n",res);
    return 0;
}