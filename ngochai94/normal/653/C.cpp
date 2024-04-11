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

int n,lis[200005],ans;
vector<int> wr;

bool fit(int val,int pos)
{
    if(pos&1)
    {
        if(val>lis[pos-1]&&(pos==n-1||val>lis[pos+1])) return true;
        else return false;
    }
    else
    {
        if((pos==n-1||val<lis[pos+1])&&(pos==0||val<lis[pos-1])) return true;
        else return false;
    }
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n) cin>>lis[i];
    For(i,0,n-1)
    {
        if(i&1 && lis[i]<=lis[i+1]) wr.pb(i);
        else if(i%2==0&&lis[i]>=lis[i+1]) wr.pb(i);
    }
    if(wr.size()>4)
    {
        cout<<0;return 0;
    }
    if(wr.size()==1)
    {
        int p=wr[0];
        For(i,0,p) if(fit(lis[p],i)&&fit(lis[i],p)) ans++;
        For(i,p+2,n) if(fit(lis[p],i)&&fit(lis[i],p)) ans++;
        For(i,0,p) if(fit(lis[p+1],i)&&fit(lis[i],p+1)) ans++;
        For(i,p+2,n) if(fit(lis[p+1],i)&&fit(lis[i],p+1)) ans++;
        swap(lis[p],lis[p+1]);
        if(fit(lis[p],p)&&fit(lis[p+1],p+1)) ans++;
        cout<<ans;
    }
    else if(wr.size()==2)
    {
        int p1=wr[0],p2=wr[1];
        if(p1==p2-1)
        {
            For(i,0,p1) if(fit(lis[i],p2)&&fit(lis[p2],i)) ans++;
            For(i,p2+2,n) if(fit(lis[i],p2)&&fit(lis[p2],i)) ans++;
            swap(lis[p1],lis[p2]);
            if(fit(lis[p1],p1)&&fit(lis[p2],p2)&&fit(lis[p2+1],p2+1)) ans++;
            swap(lis[p1],lis[p2]);
            swap(lis[p2],lis[p2+1]);
            if(fit(lis[p1],p1)&&fit(lis[p2],p2)&&fit(lis[p2+1],p2+1)) ans++;
            swap(lis[p2],lis[p2+1]);
            swap(lis[p1],lis[p2+1]);
            if(fit(lis[p1],p1)&&fit(lis[p2],p2)&&fit(lis[p2+1],p2+1)) ans++;
            swap(lis[p1],lis[p2+1]);
            cout<<ans;
        }
        else
        {
            if(fit(lis[p1],p2)&&fit(lis[p2],p1)) ans++;
            if(fit(lis[p1],p2+1)&&fit(lis[p2+1],p1)) ans++;
            if(fit(lis[p1+1],p2+1)&&fit(lis[p2+1],p1+1)) ans++;
            swap(lis[p1+1],lis[p2]);
            if(fit(lis[p1+1],p1+1)&&fit(lis[p2],p2)) ans++;
            cout<<ans;
        }
    }
    else if(wr.size()==3)
    {
        int p1=wr[0],p2=wr[1],p3=wr[2];
        if(p1!=p2-1&&p2!=p3-1)
        {
            cout<<0;return 0;
        }
        if(p1==p2-1&&p2==p3-1)
        {
            if(fit(lis[p1],p3)&&fit(lis[p3],p1)) ans++;
            if(fit(lis[p2],p3+1)&&fit(lis[p3+1],p2)) ans++;
            swap(lis[p2],lis[p3]);
            if(fit(lis[p2],p2)&&fit(lis[p3],p3)) ans++;
            cout<<ans;return 0;
        }
        if(p1==p2-1)
        {
            if(fit(lis[p2],p3)&&fit(lis[p3],p2)) ans++;
            if(fit(lis[p2],p3+1)&&fit(lis[p3+1],p2)) ans++;
            cout<<ans;return 0;
        }
        if(p2==p3-1)
        {
            if(fit(lis[p3],p1)&&fit(lis[p1],p3)) ans++;
            if(fit(lis[p3],p1+1)&&fit(lis[p1+1],p3)) ans++;
            cout<<ans;return 0;
        }
    }
    else if(wr.size()==4)
    {
        int p1=wr[0],p2=wr[1],p3=wr[2],p4=wr[3];
        if(p1!=p2-1||p3!=p4-1)
        {
            cout<<0;return 0;
        }
        if(fit(lis[p2],p4)&&fit(lis[p4],p2)) cout<<1;
        else cout<<0;
    }
}