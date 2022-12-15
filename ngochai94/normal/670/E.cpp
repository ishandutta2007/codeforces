#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,m,p,cor[500005];
stack<int> que;
string s,q;
set<int> lis;

int getLeft(int x)
{
    auto it=lis.lower_bound(x);
    if(it==lis.begin()) return x;
    it--;
    return *it;
}

int getRight(int x)
{
    auto it=lis.upper_bound(x);
    if(it==lis.end()) return x;
    return *it;
}

int getDel(int x)
{
    auto it=lis.upper_bound(x);
    if(it==lis.end()) return getLeft(x);
    return *it;
}

void display()
{
    for(int i:lis) cout<<s[i];
    cout<<endl;
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>p>>s>>q;
    p--;
    For(i,0,n)
    {
        if(s[i]=='(') que.push(i);
        else
        {
            int val=que.top(); que.pop();
            cor[i]=val;
            cor[val]=i;
        }
    }
    For(i,0,n) lis.insert(i);
    For(i,0,m)
    {
        if(q[i]=='R')
        {
            p=getRight(p);
        }
        else if(q[i]=='L')
        {
            p=getLeft(p);
        }
        else
        {
            int val=cor[p];
            if(val<p) swap(val,p);
            if(getLeft(p)==p&&getRight(val)==val) continue;
            //cout<<p<<' '<<val<<endl;
            auto it=lis.find(val);
            it++;
            lis.erase(lis.find(p),it);
            p=getDel(p);
            //display();
        }
        //cout<<p<<endl;
    }
    display();
}