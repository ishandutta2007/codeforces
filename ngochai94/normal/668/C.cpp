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

int n;
long double A,B,a[100005],b[100005],M[100005],m[100005],s;

long double solve(long double a,long double b,long double c,long double cap)
{
    long double delta = b*b-4*a*c;
    if(delta<1e-15) delta=0;
    long double ans1 = (-b+sqrt(delta))/(2*a);
    long double ans2 = (-b-sqrt(delta))/(2*a);
    //cout<<a<<' '<<b<<' '<<c<<' '<<delta<<' '<<ans1<<endl;
    //if(A>B) return ans2;
    return ans1;
    if(ans1>=eps&&ans1<=cap-eps) return ans1;
    if(ans2>=eps&&ans2<=cap-eps) return ans2;
    if(ans1>=0&&ans1<=cap) return ans1;
    return ans2;
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    //scanf("%d",&n);
    cin>>n;
    For(i,0,n)
    {
        cin>>M[i];
    }
    For(i,0,n)
    {
        cin>>m[i];
    }
    A=B=0;
    For(i,0,n)
    {
        s=M[i]+m[i];
        a[i] = solve(1,B-A-s,M[i]-B*s,s);
        b[i] = s - a[i];
        A+=b[i];
        B+=a[i];
    }
    cout<<setprecision(8);
    For(i,0,n)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
    For(i,0,n)
    {
        cout<<b[i]<<' ';
    }
}