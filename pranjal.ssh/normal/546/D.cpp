#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)

int p[5000001];
int nop[5000001];
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int T;
    cin>>T;
    p[0]=p[1]=1;
    FOR(i,2,5000000)p[i]=i;
    FOR(i,2,2240)
    {
        if(p[i]==i)
        {
            for(int j=i*i;j<=5000000;j+=i)p[j]=i;
            //p[i]=i;
        }
    }
    nop[1]=0;
    nop[2]=1;int x=0;int j;
    FOR(i,2,5000000)
    {
        x=0;
        j=i;
        while(j!=1){j/=p[j];++x;}
        nop[i]=nop[i-1]+x;
    }
    while(T--)
    {
        int a,b;cin>>a>>b;
        cout<<nop[a]-nop[b]<<"\n";
    }
    return 0;
}