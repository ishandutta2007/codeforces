#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

int n,m,q,ans[100005],t[100005],x[100005],y[100005],r,c,curans;
int sumrow[1111], toggle[1111], book[1111][1111];
vector<int> adj[100005];

void f(int cur)
{
    //cout<<cur<<' '<<t[cur]<<endl;
    bool flag=false;
    if(t[cur]==1)
    {
        r=x[cur];c=y[cur];
        //cout<<r<<' '<<c<<' '<<(book[r][c]^toggle[r])<<endl;
        if(book[r][c]^toggle[r]==0)
        {
            flag=true;
            book[r][c]=1-book[r][c];
            curans++;
            sumrow[r]++;
        }
    }
    else if(t[cur]==2)
    {
        r=x[cur];c=y[cur];
        if(book[r][c]^toggle[r]==1)
        {
            flag=true;
            book[r][c]=1-book[r][c];
            curans--;
            sumrow[r]--;
        }
    }
    else if(t[cur]==3)
    {
        r=x[cur];
        toggle[r]=1-toggle[r];
        curans+=m-2*sumrow[r];
        sumrow[r]=m-sumrow[r];
    }
    ans[cur]=curans;
    for(int nex:adj[cur]) f(nex);
    if(t[cur]==2)
    {
        r=x[cur];c=y[cur];
        if(flag)
        {
            book[r][c]=1-book[r][c];
            curans++;
            sumrow[r]++;
        }
    }
    else if(t[cur]==1)
    {
        r=x[cur];c=y[cur];
        if(flag)
        {
            book[r][c]=1-book[r][c];
            curans--;
            sumrow[r]--;
        }
    }
    else if(t[cur]==3)
    {
        r=x[cur];
        toggle[r]=1-toggle[r];
        curans+=m-2*sumrow[r];
        sumrow[r]=m-sumrow[r];
    }
    //cout<<"after "<<curans<<endl;
    //cout<<cur<<' '<<ans[cur]<<endl;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d %d %d", &n, &m, &q);
    For(i,1,1+q)
    {
        scanf("%d", &t[i]);
        if(t[i]>2)
        {
            scanf("%d", &x[i]);
            if(t[i]==3) x[i]--;
        }
        else
        {
            scanf("%d %d", &x[i], &y[i]);
            x[i]--;y[i]--;
        }
        if(t[i]==4) adj[x[i]].pb(i);
        else adj[i-1].pb(i);
    }
    f(0);
    For(i,1,1+q) cout<<ans[i]<<endl;
}