#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int t[1007];

int ask(int i,int j,int l)
{
    cout<<"? "<<i<<" "<<j<<" "<<l<<endl;
    int x;
    cin>>x;
    return x;
   // return max({t[i],t[j],t[l]})-min({t[i],t[j],t[l]});
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n;
        cin>>n;
       /* n=rand()%1000+1;
        cout<<n<<endl;
        for(int i=1;i<=n;i++) t[i]=rand()%10000+1;
        t[n]=0;*/
        set<int>S;
        for(int i=1;i<=n;i++) S.insert(i);
        int last=ask(1,2,3),c=1;
        while(sz(S)>3)
        {
            set<int>::iterator it=++S.begin();
            int x=*it,y=*++it,z=*++it;
            int k1=ask(c,x,z),k2=ask(x,y,z);
            if(last>max(k1,k2)) S.erase(z);
            else
            {
                if(k2>=k1)
                {
                    S.erase(c);
                    c=x;
                }
                else
                {
                    S.erase(y);
                }
                last=max(k1,k2);
            }
        }
        set<int>::iterator it=S.begin();
        int x=*it,y=*++it,z=*++it,a=-1;
        for(int i=1;i<=n;i++)
        {
            if(i==x||i==y||i==z) continue;
            a=i;
        }
        int c1=ask(x,y,a);
        int c2=ask(x,z,a);
        int c3=ask(y,z,a);
        if(c1==last) cout<<"! "<<x<<" "<<y<<endl;
        else if(c2==last) cout<<"! "<<x<<" "<<z<<endl;
        else if(c3==last) cout<<"! "<<y<<" "<<z<<endl;
        else
        {
            if(c1>c2) cout<<"! "<<x<<" "<<y<<endl;
            else cout<<"! "<<x<<" "<<z<<endl;
        }
    }

    return 0;
}