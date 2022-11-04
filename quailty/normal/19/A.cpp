#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=55;
map<string,int> mp;
inline int get_id(const string &str)
{
    if(!mp[str])mp[str]=(int)mp.size();
    return mp[str];
}
struct team
{
    string name;
    int pts,dif,sg;
    bool operator < (const team &rhs)const
    {
        if(pts==rhs.pts)
        {
            if(dif==rhs.dif)
                return sg>rhs.sg;
            return dif>rhs.dif;
        }
        return pts>rhs.pts;
    }
}t[MAXN];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        get_id(str);
        t[i].name=str;
    }
    for(int i=1;i<=n*(n-1)/2;i++)
    {
        string str;
        cin>>str;
        int cut=str.find('-');
        int l=get_id(str.substr(0,cut));
        int r=get_id(str.substr(cut+1));
        int a,b;
        scanf("%d:%d",&a,&b);
        t[l].pts+=(a>b ? 3 : (a<b ? 0 : 1));
        t[l].dif+=a-b;
        t[l].sg+=a;
        t[r].pts+=(b>a ? 3 : (b<a ? 0 : 1));
        t[r].dif+=b-a;
        t[r].sg+=b;
    }
    sort(t+1,t+n+1);
    vector<string> res;
    for(int i=1;i<=n/2;i++)
        res.push_back(t[i].name);
    sort(res.begin(),res.end());
    for(int i=0;i<n/2;i++)
        cout<<res[i]<<endl;
    return 0;
}