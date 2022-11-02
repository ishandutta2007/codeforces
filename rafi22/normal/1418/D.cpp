#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

set<int> zbior;
set<int>::iterator it,it1;
multiset <int> mini;

void ins(int a)
{
    it=zbior.upper_bound(a);
    int u=*it,l=*--it;
    mini.erase(mini.find(u-l));
    mini.insert(a-l);
    mini.insert(u-a);
    zbior.insert(a);
}
void del(int a)
{
    zbior.erase(a);
    it=zbior.upper_bound(a);
    int u=*it,l=*--it;
    mini.insert(u-l);
    mini.erase(mini.find(u-a));
    mini.erase(mini.find(a-l));
}
void read()
{
    if(zbior.size()<=2)
    {
        cout<<0<<endl;
        return ;
    }
    int p,k,g;
    it=zbior.end();
    it--;
    it--;
    k=*it;
    it=zbior.begin();
    it++;
    p=*it;
    it=mini.end();
    it--;
    it--;
    it--;
    g=*it;
    cout<<max((int)0,k-p-g)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        zbior.insert(-inf);
        zbior.insert(inf);
        mini.insert(2*inf);
        int n,m,t,a;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            ins(a);
        }
        read();
        for(int i=0;i<m;i++)
        {
            cin>>t>>a;
            if(t==0) del(a);
            else ins(a);
            read();
        }
    }

    return 0;
}