#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-12
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

double a,b,c,d,A,B,C;
vector<double> ans;
double res;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin>>a>>b>>c>>d;
    For(ia,-1,2) For(ib,-1,2) For(ic,-1,2) For(id,-1,2) if(ia&&ib&&ic&&id)
    {
        A=ia*id-ib*ic;
        B=d*ia+a*id-c*ib-b*ic;
        C=a*d-b*c;
        if(A==0)
        {
            if(B==0)
            {
                if(C==0)
                {
                    cout<<"0.0";return 0;
                }
                continue;
            }
            ans.pb(-1.0*C/B);
        }
        else
        {
            double del=B*B-4*A*C;
            if(del<0) continue;
            ans.pb((-B+sqrt(del))/(2*A));
            ans.pb((-B-sqrt(del))/(2*A));
        }
    }
    res=1000000000.0;
    for(double x:ans) res=min(res,abs(x));
    //cout<<res;
    printf("%.11f",res);
}