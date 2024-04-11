#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    scanf("%i %i %i",&n,&m,&k);
    bool slobodno[n];
    for(int i=0;i<n;i++)
    {
        slobodno[i]=true;
    }
    for(int i=0;i<m;i++)
    {
        int s;
        scanf("%i",&s);
        slobodno[s]=false;
    }
    int costs[k+1];
    for(int i=0;i<k;i++)
    {
        scanf("%i",&costs[i+1]);
    }
    if(slobodno[0]==false)
    {
        printf("-1\n");
        return 0;
    }
    int max_block=0;
    int prosli[n];
    prosli[0]=0;
    for(int i=1;i<n;i++)
    {
        if(slobodno[i]==false)
        {
            prosli[i]=prosli[i-1];
            max_block=max(max_block,i-prosli[i]);
        }
        else
        {
            prosli[i]=i;
        }
    }
    if(k<=max_block)
    {
        printf("-1\n");
        return 0;
    }
    deque<pair<int,int> > sorted;
    sorted.push_back(make_pair(max_block+1,costs[max_block+1]));
    for(int i=max_block+2;i<=k;i++)
    {
        pair<int,int> pr=sorted.back();
        while(pr.second>=costs[i]&&(!sorted.empty()))
        {
            sorted.pop_back();
            if(!sorted.empty())
            pr=sorted.back();
        }
        sorted.push_back(make_pair(i,costs[i]));
    }
    vector<pair<int,int> > cos;
    while(!sorted.empty())
    {
        cos.push_back(sorted.front());
        sorted.pop_front();
        //printf("%i %i",cos[cos.size()-1].first,cos[cos.size()-1].second);
    }
    long long minn=-1;
    for(int i=0;i<cos.size();i++)
    {
        int jump=cos[i].first;
        int number=0;
        int tr=0;
        while(tr<n)
        {
            number++;
            int sl=tr+jump;
            if(sl<n)
            {
                tr=prosli[tr+jump];
            }
            else
            {
                tr=sl;
            }
        }
        if(minn==-1)
        {
            minn=(long long)number*cos[i].second;
        }
        else
        {
            minn=min(minn,(long long)number*cos[i].second);
        }
    }
    printf("%I64d\n",minn);
    return 0;
}