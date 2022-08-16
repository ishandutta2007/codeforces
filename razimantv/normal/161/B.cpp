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
    int sz,i,type;
    two(int a=0,int b=0,int c=0)
    {
        sz=a,i=b,type=c;
    }
};

bool operator<(const two&t1,const two&t2)
{
    return t1.sz>t2.sz;
}

vector<two> cart[1000],stool,pencil;

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    
    for(int i=1;i<=N;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(b==1)stool.push_back(two(a,i,0));
        else pencil.push_back(two(a,i,1));
    }
    
    sort(pencil.begin(),pencil.end());
    sort(stool.begin(),stool.end());
    
    int done=0;
    for(int i=0;i<stool.size();i++)
    {
        if(done<K)cart[done++].push_back(stool[i]);
        else cart[K-1].push_back(stool[i]);
    }
    for(int i=0;i<pencil.size();i++)
    {
        if(done<K)cart[done++].push_back(pencil[i]);
        else cart[K-1].push_back(pencil[i]);
    }
    
    long long tot=0;
    for(int i=0;i<K;i++)
    {
        int least=cart[i][0].sz;
        for(int j=0;j<cart[i].size();j++)
        {
            tot+=(cart[i][j].sz<<1);
            least=min(least,cart[i][j].sz);
        }
        if(cart[i][0].type==0)tot-=least;
    }
    //cout<<tot<<endl;
    cout<<tot/2<<"."<<(tot&1)*5<<endl;
    for(int i=0;i<K;i++)
    {
        cout<<cart[i].size();
        for(int j=0;j<cart[i].size();j++)
            cout<<" "<<cart[i][j].i;
        cout<<endl;
    }
    return 0;
}