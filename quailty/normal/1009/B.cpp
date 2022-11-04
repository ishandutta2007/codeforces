#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char str[MAXN];
vector<pair<int,int> > tmp,seg;
int main()
{
    scanf("%s",str);
    int cnt=0;
    for(int i=0,j=0;str[i];i=j)
    {
        while(str[i]==str[j])j++;
        if(str[i]=='0' || str[i]=='2')
            tmp.push_back({str[i]-'0',j-i});
        else cnt+=j-i;
    }
    for(int i=0,j=0;i<(int)tmp.size();i=j)
    {
        int sum=0;
        while(j<(int)tmp.size() && tmp[j].first==tmp[i].first)
            sum+=tmp[j++].second;
        seg.push_back({tmp[i].first,sum});
    }
    if(seg.empty() || seg[0].first==2)
        seg.insert(seg.begin(),{1,cnt});
    else seg.insert(seg.begin()+1,{1,cnt});
    for(int i=0;i<(int)seg.size();i++)
        for(int j=0;j<seg[i].second;j++)
            printf("%d",seg[i].first);
    return 0;
}