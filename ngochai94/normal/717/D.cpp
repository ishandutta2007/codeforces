#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 10007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

long long x,n;
long double ori[130][130], tran[130][130], tmp[130][130], p[130];

void mul()
{
    For(i,0,130) For(j,0,130)
    {
        tmp[i][j]=0;
        For(k,0,130) tmp[i][j]+=ori[i][k]*tran[k][j];
    }
    For(i,0,130) For(j,0,130) ori[i][j]=tmp[i][j];
}
void expo()
{
    For(i,0,130) For(j,0,130)
    {
        tmp[i][j]=0;
        For(k,0,130) tmp[i][j]+=ori[i][k]*ori[k][j];
    }
    For(i,0,130) For(j,0,130) ori[i][j]=tmp[i][j];
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>x;
    For(i,0,x+1) cin>>p[i];
    For(i,0,130)
    {
        For(j,0,130)
        {
            int k = i^j;
            if(k<=x) tran[i][j]=p[k];
            else tran[i][j]=0;
        }
    }
    For(i,0,130) For(j,0,130)
    {
        if(i==j) ori[i][j]=1;
        else ori[i][j]=0;
    }
    for(int i=30; i>=0; i--)
    {
        expo();
        if((1<<i)&n) mul();
    }
    cout<<setprecision(11);
    cout<<1.0-ori[0][0];
}