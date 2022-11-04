#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
char str[MAXN];
int main()
{
    scanf("%s",str);
    vector<pair<char,int> > now,tmp;
    for(int i=0,j=0;str[i];i=j)
    {
        while(str[i]==str[j])j++;
        now.push_back(make_pair(str[i],j-i));
    }
    int res=0;
    while((int)now.size()>1)
    {
        for(int i=0;i+1<(int)now.size();i++)
            now[i].second--;
        for(int i=1;i<(int)now.size();i++)
            now[i].second--;
        tmp.clear();
        for(int i=0;i<(int)now.size();i++)
            if(now[i].second>0)tmp.push_back(now[i]);
        now.clear();
        for(int i=0,j=0;i<(int)tmp.size();i=j)
        {
            int tot=0;
            while(j<(int)tmp.size() && tmp[i].first==tmp[j].first)tot+=tmp[j++].second;
            now.push_back(make_pair(tmp[i].first,tot));
        }
        res++;
    }
    printf("%d\n",res);
    return 0;
}