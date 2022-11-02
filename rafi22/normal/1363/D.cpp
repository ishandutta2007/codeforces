#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define pob pop_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,s,a;
        cin>>n>>k;
        vector<int>tab[k+1];
        set <int> other;
        for(int i=1;i<=n;i++) other.insert(i);
        int pref[k+1];
        int res[k+1];
        pref[0]=0;
        for(int i=1; i<=k; i++)
        {
            cin>>s;
            for(int j=0; j<s; j++)
            {
                cin>>a;
                other.erase(a);
                tab[i].push_back(a);
            }
            pref[i]=pref[i-1]+tab[i].size();
        }
        int l=1,p=k,last,x;
        cout<<"? "<<pref[p]-pref[l-1]<<" ";
        fflush(stdout);
        for(int i=l; i<=p; i++)
        {
            for(int j=0; j<tab[i].size(); j++)
            {
                cout<<tab[i][j]<<" ";
                 fflush(stdout);
            }
        }
        cout<<endl;
        fflush(stdout);
        cin>>x;
        if(x==-1) return 0;
        last=x;
        while(l<p)
        {
            int sr=(p+l)/2;
            cout<<"? "<<pref[sr]-pref[l-1]<<" ";
            fflush(stdout);
            for(int i=l; i<=sr; i++)
            {
                for(int j=0; j<tab[i].size(); j++)
                {
                    cout<<tab[i][j]<<" ";
                    fflush(stdout);
                }
            }
            cout<<endl;
            fflush(stdout);
            cin>>x;
            if(x==-1) return 0;
            if(x==last) p=sr;
            else l=sr+1;
        }

        for(int i=1; i<=k; i++)
        {
            if(i!=l) res[i]=last;
        }
        cout<<"? "<<pref[k]-tab[l].size()+other.size()<<" ";
        fflush(stdout);
        for(int i=1; i<=k; i++)
        {
            if(i==l) continue;
            for(int j=0; j<tab[i].size(); j++)
            {
                cout<<tab[i][j]<<" ";
                fflush(stdout);
            }
        }
        for(set<int>::iterator it=other.begin();it!=other.end();it++)
        {
            cout<<*it<<" ";
            fflush(stdout);
        }
        cout<<endl;
        fflush(stdout);
        cin>>x;
        if(x==-1) return 0;
        res[l]=x;
        cout<<"! ";
        for(int i=1; i<=k; i++) cout<<max(res[i],x)<<" ";
        cout<<endl;
        string str;
        cin>>str;
        if(str=="Incorrect") return 0;
    }
    return 0;
}