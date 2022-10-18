#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int mod=998244353;
const int N=2001;
vector<vector<int> > graf(N);
int powmod(int k)
{
    int x=2,ans=1;
    for(;k;k>>=1,x=(ll)x*x%mod)
        if(k&1)
            ans=(ll)ans*x%mod;
    return ans;
}
int main()
{
	string s;
	cin >> s;
	int n=s.size();
	if(s[n-1]=='1')
    {
        printf("0\n");
        return 0;
    }
    s[n-1]='0';
    int sol=0;
    for(int i=1;i<n;i++)
    {
        vector<vector<pair<int,int> > > graf(2*n);
        for(int j=0;j<n/2;j++)
            graf[j].pb({n-1-j,0}),graf[n-1-j].pb({j,0});
        for(int j=i;j<(n+i)/2;j++)
        {
            graf[n+j].pb({n-1-j+i+n,0}),graf[n-1-j+i+n].pb({n+j,0});
        }
        for(int j=0;j<n;j++)
        {
            if(s[j]=='0')
                graf[j].pb({j+n,0}),graf[n+j].pb({j,0});
            if(s[j]=='1')
                graf[j].pb({j+n,1}),graf[n+j].pb({j,1});
        }
        vector<int> visited(2*n,-1);
        int cnt=0;
        bool uspeo=true;
        for(int j=0;j<n;j++)
        {
            if(visited[j]!=-1)
                continue;
            vector<int> komp;
            queue<int> q;
            q.push(j);
            visited[j]=1;
            cnt++;
            while(q.size())
            {
                int tr=q.front();
                komp.pb(tr);
                q.pop();
                for(auto p:graf[tr])
                {
                    int sl=visited[tr]^p.s;
                    if(visited[p.f]!=-1)
                    {
                        if(visited[p.f]!=sl)
                            uspeo=false;
                        continue;
                    }
                    visited[p.f]=sl;
                    q.push(p.f);
                }
            }
            vector<int> cntt(2);
            for(auto p:komp)
                if(p>=n&&p<n+i)
                    cntt[visited[p]]++;
            if(cntt[0]&&cntt[1])
                uspeo=false;
            if(cntt[0]||cntt[1])
                cnt--;
        }
        for(int j=i;j<n;j++)
        {
            if(visited[j+n]!=-1)
                continue;
            vector<int> komp;
            queue<int> q;
            q.push(j+n);
            visited[j+n]=1;
            cnt++;
            while(q.size())
            {
                int tr=q.front();
                komp.pb(tr);
                q.pop();
                for(auto p:graf[tr])
                {
                    int sl=visited[tr]^p.s;
                    if(visited[p.f]!=-1)
                    {
                        if(visited[p.f]!=sl)
                            uspeo=false;
                        continue;
                    }
                    visited[p.f]=sl;
                    q.push(p.f);
                }
            }
            vector<int> cntt(2);
            for(auto p:komp)
                if(p>=n&&p<n+i)
                    cntt[visited[p]]++;
            if(cntt[0]&&cntt[1])
                uspeo=false;
            if(cntt[0]||cntt[1])
                cnt--;
        }
        if(uspeo){
            sol=sol+powmod(cnt);
            if(sol>mod)
                sol-=mod;
        }
    }
    printf("%i\n",sol);
    return 0;
}