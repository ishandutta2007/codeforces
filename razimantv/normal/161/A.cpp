# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cctype>
# include <set>
# include <map>
# include <cmath>
# include <queue>
# include <string>

using namespace std;

struct two
{
    int sz,i;
}soldier[100000],vest[100000];

bool operator<(const two&t1,const two&t2)
{
    return t1.sz<t2.sz;
}

vector<int> s,v;

int main()
{
    int M,N,A,B;
    scanf("%d%d%d%d",&M,&N,&A,&B);
    
    for(int i=0;i<M;i++)
    {
        scanf("%d",&soldier[i].sz);
        soldier[i].i=i;
    }
    sort(soldier,soldier+M);
    
    for(int i=0;i<N;i++)
    {
        scanf("%d",&vest[i].sz);
        vest[i].i=i;
    }
    sort(vest,vest+N);
    
    for(int i=0,j=0;i<M&&j<N;)
    {
        if(soldier[i].sz>=vest[j].sz-B&&soldier[i].sz<=vest[j].sz+A)
        {
            s.push_back(soldier[i++].i);
            v.push_back(vest[j++].i);
        }
        else if(soldier[i].sz<vest[j].sz-B)i++;
        else j++;
    }
    
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
        cout<<s[i]+1<<" "<<v[i]+1<<endl;
    return 0;
}