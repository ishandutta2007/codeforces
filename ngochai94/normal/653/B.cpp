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

int n,q,ans;
string s;
map<string,char> dic;

bool can(string x)
{
    while(x.size()>1)
    {
        string tmp = x.substr(0,2);
        if(dic.count(tmp))
        {
            x=dic[tmp]+x.substr(2,x.size()-2);
        }
        else return false;
    }
    if(x=="a") return true;
    return false;
}

void rec(int p)
{
    For(i,0,6)
    {
        char c='a'+i;
        s[p]=c;
        if(p==n-1)
        {
            if(can(s)) ans++;
        }
        else rec(p+1);
    }
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    ans=0;
    cin>>n>>q;
    while(q--)
    {
        char c;
        cin>>s>>c;
        dic[s]=c;
    }
    s="";
    For(i,0,n) s+=' ';
    rec(0);
    cout<<ans;
}