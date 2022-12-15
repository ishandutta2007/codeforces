#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 10007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

long long n,low,high,chs;
long long x1up,x2up,x1down,x2down,y1down,y2down,y1up,y2up;

int query(long long x, long long y, long long xx, long long yy)
{
    cout<<"? "<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
    cout<<flush;
    int res;
    cin>>res;
    return res;
}

int query2(long long x, long long y, long long xx, long long yy)
{
    int res=query(x,y,xx,yy);
    if(x<=x1down&&y<=y1down&&xx>=x1up&&yy>=y1up) res--;
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin>>n;
    low=1;high=n;
    while(low<high)
    {
        chs=(low+high)/2;
        int res=query(1,1,n,chs);
        if(res==0) low=chs+1;
        else high=chs;
    }
    y1up=low;
    low=1;high=n;
    while(low<high)
    {
        chs=(low+high)/2;
        int res=query(1,1,chs,y1up);
        if(res==0) low=chs+1;
        else high=chs;
    }
    x1up=low;
    low=1; high=x1up;
    //cout<<'a'<<x1up<<y1up;
    while(low<=high)
    {
        chs=(low+high)/2;
        int res=query(chs,1,x1up,y1up);
        if(res!=0)
        {
            low=chs+1;
            x1down=chs;
        }
        else high=chs-1;
    }
    low=1;high=y1up;
    while(low<=high)
    {
        chs=(low+high)/2;
        int res=query(x1down,chs,x1up,y1up);
        if(res!=0)
        {
            low=chs+1;
            y1down=chs;
        }
        else high=chs-1;
    }


    low=1;high=n;
    while(low<high)
    {
        chs=(low+high)/2;
        int res=query2(1,1,n,chs);
        if(res==0) low=chs+1;
        else high=chs;
    }
    y2up=low;
    low=1;high=n;
    while(low<high)
    {
        chs=(low+high)/2;
        int res=query2(1,1,chs,y2up);
        if(res==0) low=chs+1;
        else high=chs;
    }
    x2up=low;
    low=1; high=x2up;
    while(low<=high)
    {
        chs=(low+high)/2;
        int res=query2(chs,1,x2up,y2up);
        if(res!=0)
        {
            low=chs+1;
            x2down=chs;
        }
        else high=chs-1;
    }
    low=1;high=y2up;
    while(low<=high)
    {
        chs=(low+high)/2;
        int res=query2(x2down,chs,x2up,y2up);
        if(res!=0)
        {
            low=chs+1;
            y2down=chs;
        }
        else high=chs-1;
    }
    cout<<"! "<<x1down<<" "<<y1down<<" "<<x1up<<" "<<y1up<<" "<<x2down<<" "<<y2down<<" "<<x2up<<" "<<y2up<<endl;
    cout<<flush;
}