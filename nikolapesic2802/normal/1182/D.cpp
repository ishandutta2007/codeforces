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

const int mod=1e9+7;
struct node{
    vector<int> nxt,dp,pref,suf;
    void construct(int tr)
    {
        pref=suf=dp;
        for(int i=1,n=dp.size();i<n;i++)
            if(pref[i]==pref[i-1])
                pref[i]=pref[i-1];
            else
                pref[i]=-1;
        for(int n=dp.size(),i=n-2;i>=0;i--)
            if(suf[i]==suf[i+1])
                suf[i]=suf[i+1];
            else
                suf[i]=-1;
    }
    int getWithout(int i)
    {
        int sol=INT_MAX;
        if(i)
            sol=pref[i-1];
        if(i!=(int)pref.size()-1)
        {
            if(sol==INT_MAX)
                sol=suf[i+1];
            else
            {
                if(sol!=suf[i+1])
                    sol=-1;
            }
        }
        return sol;
    }
    int getSol()
    {
        return pref[pref.size()-1];
    }
};
const int N=1e5+5;
vector<node> graf(N);
int init(int tr,int par)
{
    int h=INT_MAX;
    for(int i=0;i<(int)graf[tr].nxt.size();i++)
    {
        int p=graf[tr].nxt[i];
        if(p==par)
            continue;
        int d=init(p,tr);
        graf[tr].dp[i]=d;
        if(h==INT_MAX)
            h=d;
        else
            if(h!=d)
                h=-1;
    }
    if(h==-1)
        return -1;
    if(h==INT_MAX)
        h=0;
    h=((ll)h*N+graf[tr].nxt.size())%mod;
    return h;
}
void solve(int tr,int par)
{
    graf[tr].construct(tr);
    if(graf[tr].getSol()!=-1)
    {
        printf("%i\n",tr+1);
        exit(0);
    }
    for(int i=0;i<(int)graf[tr].nxt.size();i++)
    {
        int p=graf[tr].nxt[i];
        if(p==par)
            continue;
        int sol=graf[tr].getWithout(i);
        if(sol==INT_MAX)
            sol=0;
        if(sol!=-1)
            sol=((ll)sol*N+graf[tr].nxt.size())%mod;
        for(auto &d:graf[p].dp)
            if(d==INT_MAX)
                d=sol;
        solve(p,tr);
    }
}
int main()
{
	int n;
	scanf("%i",&n);
	if(n==1)
    {
        printf("1\n");
        return 0;
    }
	for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;b--;
        graf[a].nxt.pb(b);
        graf[b].nxt.pb(a);
        graf[a].dp.pb(INT_MAX);
        graf[b].dp.pb(INT_MAX);
    }
    init(0,-1);
    solve(0,-1);
    printf("-1\n");
    return 0;
}