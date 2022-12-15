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

int n,plu,minu;
string s;
char c;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    plu=1;
    while(cin>>c)
    {
        if(c=='+')
        {
            plu++;
            s+=c;
        }
        else if(c=='-')
        {
            minu++;
            s+=c;
        }
        else if(c=='=') break;
    }
    cin>>n;
    if(plu*n-minu<n||plu-minu*n>n)
    {
        cout<<"Impossible";return 0;
    }
    //cout<<plu<<' '<<minu<<endl;
    For(i,1,n+1)
    {
        int rem = n+minu*i;
        int each = rem/plu;
        int re = rem%plu;
        int com = re==0?each:each+1;
        //cout<<i<<' '<<rem<<' '<<each<<' '<<com<<endl;
        if(each<1||com<1||each>n||com>n) continue;
        cout<<"Possible"<<endl;
        if(re)
        {
            cout<<com;re--;
        }
        else cout<<each;
        for(char c:s)
        {
            if(c=='+')
            {
                cout<<" + ";
                if(re)
                {
                    cout<<com;re--;
                }
                else cout<<each;
            }
            else
            {
                cout<<" - "<<i;
            }
        }
        cout<<" = "<<n;
        return 0;
    }
    cout<<"Impossible";
}