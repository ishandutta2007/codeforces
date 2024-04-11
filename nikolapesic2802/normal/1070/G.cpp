#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<
pair<int,pair<int,int> >,
null_type,
less<pair<int,pair<int,int> > >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define ll long long
#define pb push_back
ordered_set heroji;
bool test(int p,int n,vector<int> board)
{
    int poz=(*heroji.find_by_order(p)).first;
    int hp=(*heroji.find_by_order(p)).second.first;
    if(poz>n)
    {
        for(int i=poz-1;i>=n;i--)
        {
            hp+=board[i];
            if(hp<0)
                return false;
        }
    }
    if(poz<n)
    {
        for(int i=poz+1;i<=n;i++)
        {
            hp+=board[i];
            if(hp<0)
                return false;
        }
    }
    return true;
}
vector<int> fail={-1};
vector<int> solve(int l,int r,int n,vector<int> board)
{
    if(l>r)
    {
        vector<int> kk;
        return kk;
    }
    if(l==r)
    {
        if(test(l,n,board))
        {
            vector<int> lol;
            lol.pb((*heroji.find_by_order(l)).second.second);
            return lol;
        }
        return fail;
    }
    int levi=-1,desni=-1;
    int i=l;
    while((*heroji.find_by_order(i)).first<n&&i<=r)
    {
        if(test(i,n,board))
        {
            levi=i;
            break;
        }
        i++;
    }
    i=r;
    while((*heroji.find_by_order(i)).first>n&&i>=l)
    {
        if(test(i,n,board))
        {
            desni=i;
            break;
        }
        i--;
    }
    if(desni==-1&&levi==-1)
    {
        return fail;
    }
    vector<int> res;
    if(levi!=-1)
    {
        assert((*heroji.find_by_order(levi)).first<n);
        for(i=n;i>(*heroji.find_by_order(levi)).first;i--)
            board[i]=0;
        i=levi;
        while((*heroji.find_by_order(i)).first<n&&i<=r)
        {
            res.pb((*heroji.find_by_order(i)).second.second);
            i++;
        }
        if(i<=r&&(*heroji.find_by_order(i)).first==n)
        {
            res.pb((*heroji.find_by_order(i)).second.second);
            i++;
        }
        vector<int> s=solve(i,r,n,board);
        if(s==fail)
            return fail;
        vector<int> dd=solve(l,levi-1,n,board);
        if(dd==fail)
            return fail;
        for(auto p:s)
        {
            res.pb(p);
        }
        for(auto p:dd)
        {
            res.pb(p);
        }
        return res;
    }
    else
    {
        assert(desni!=-1);
        assert((*heroji.find_by_order(desni)).first>n);
        for(i=n;i<(*heroji.find_by_order(desni)).first;i++)
            board[i]=0;
        i=desni;
        while((*heroji.find_by_order(i)).first>n&&i>=l)
        {
            res.pb((*heroji.find_by_order(i)).second.second);
            i--;
        }
        if(i>=l&&(*heroji.find_by_order(i)).first==n)
        {
            res.pb((*heroji.find_by_order(i)).second.second);
            i--;
        }
        vector<int> s=solve(l,i,n,board);
        if(s==fail)
            return fail;
        vector<int> dd=solve(desni+1,r,n,board);
        if(dd==fail)
            return fail;
        for(auto p:s)
        {
            res.pb(p);
        }
        for(auto p:dd)
        {
            res.pb(p);
        }
        return res;
    }
}
int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    vector<int> board(n);
    for(int i=0;i<m;i++)
    {
        int a,h;
        scanf("%i %i",&a,&h);
        heroji.insert({a-1,{h,i+1}});
    }
    for(int i=0;i<n;i++)
    {
        scanf("%i",&board[i]);
    }
    for(int i=0;i<n;i++)
    {
        vector<int> s=solve(0,m-1,i,board);
        if(s!=fail)
        {
            printf("%i\n",i+1);
            for(auto p:s)
            {
                printf("%i ",p);
            }
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}