#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int X[8]={0,1,6,4,2,3,5,4};

int t[10007];

int ask(bool b,int i,int j)
{
    int x;
    if(b)
    {
        cout<<"or "<<i<<" "<<j<<endl;
        //return X[i]|X[j];
    }
    else
    {
        cout<<"and "<<i<<" "<<j<<endl;
       // return X[i]&X[j];
    }
    cin>>x;
    return x;
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
        int n,k;
        cin>>n>>k;
        int a1=ask(0,1,2),a2=ask(1,1,2);
        int b1=ask(0,2,3),b2=ask(1,2,3);
        int c1=ask(0,3,1),c2=ask(1,3,1);
        for(int j=30;j>=0;j--)
        {
            int a,b,c;
            if(!(a2&(1<<j))) a=0;
            else if((a1&(1<<j))) a=2;
            else a=1;
            if(!(b2&(1<<j))) b=0;
            else if((b1&(1<<j))) b=2;
            else b=1;
            if(!(c2&(1<<j))) c=0;
            else if((c1&(1<<j))) c=2;
            else c=1;
          //  cout<<a<<" "<<b<<" "<<c<<endl;
            if(a==0)
            {
                if(b>0) t[3]+=(1<<j);
            }
            else if(a==2)
            {
                t[1]+=(1<<j);
                t[2]+=(1<<j);
                if(b>1) t[3]+=(1<<j);
            }
            else if(b==0)
            {
                if(a>0) t[1]+=(1<<j);
            }
            else if(b==2)
            {
                t[2]+=(1<<j);
                t[3]+=(1<<j);
                if(a>1) t[1]+=(1<<j);
            }
            else if(c==0)
            {
                if(b>0) t[2]+=(1<<j);
            }
            else if(c==2)
            {
                t[3]+=(1<<j);
                t[1]+=(1<<j);
                if(b>1) t[2]+=(1<<j);
            }
            else return 2137;
        }
        for(int i=4;i<=n;i++)
        {
            int a=ask(0,1,i);
            int b=ask(1,1,i);
            for(int j=30;j>=0;j--)
            {
                if(!(b&(1<<j))) ;
                else if((a&(1<<j))) t[i]+=(1<<j);
                else if(!(t[1]&(1<<j))) t[i]+=(1<<j);
            }
        }
        sort(t+1,t+n+1);
        cout<<"finish "<<t[k]<<endl;
    }

    return 0;
}