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

const int N=1<<17;
vector<int> degree(N),dep(N),special(N);
int cnt=0;
vector<vector<int> > graf(N),sinovi(N);
int main()
{
    int n,a,b;
    scanf("%i",&n);
    int m=1<<n;
    m-=2;
    for(int i=1;i<m;i++)
        scanf("%i %i",&a,&b),graf[a].pb(b),graf[b].pb(a),degree[a]++,degree[b]++;
    for(int i=1;i<=m;i++)
        if(degree[i]==4)
            special[i]=1,cnt++;
        else
            if(degree[i]!=3)
            {
                if(degree[i]!=1&&degree[i]!=2)
                    return 0*printf("0\n");
                if(degree[i]==2)
                    cnt++;
            }
    if(cnt==0)
    {
        queue<int> leaf;
        for(int i=1;i<=m;i++)
            if(degree[i]==1)
                leaf.push(i);
        vector<int> ord;
        while(leaf.size())
        {
            int tr=leaf.front();
            ord.pb(tr);
            leaf.pop();
            for(auto p:sinovi[tr])
                dep[tr]=max(dep[tr],dep[p]+1);
            if(sinovi[tr].size()!=0&&sinovi[tr].size()!=2)
                return 0*printf("0\n");
            if(sinovi[tr].size()==2&&dep[sinovi[tr][0]]!=dep[sinovi[tr][1]])
                return 0*printf("0\n");
            for(auto p:graf[tr])
            {
                degree[p]--;
                if(degree[p]>0)
                    sinovi[p].pb(tr);
                if(degree[p]==1)
                    leaf.push(p);
            }
        }
        if(ord.size()!=m)
            return 0*printf("0\n");
        printf("2\n%i %i\n",min(ord[m-1],ord[m-2]),max(ord[m-1],ord[m-2]));
        return 0;
    }
    if(cnt!=2)
        return 0*printf("0\n");
    int koliko=0,sol=-1,cnt2=0;
    queue<int> leaf;
    for(int i=1;i<=m;i++)
        if(degree[i]==1)
            leaf.push(i);
    while(leaf.size())
    {
        int tr=leaf.front();
        cnt2++;
        leaf.pop();
        bool isto=true;
        for(int i=0;i<(int)sinovi[tr].size()-1;i++)
            if(dep[sinovi[tr][i]]!=dep[sinovi[tr][i+1]])
                isto=false;
        for(auto p:sinovi[tr])
            dep[tr]=max(dep[tr],dep[p]+1);
        if(!isto)
        {
            if(sinovi[tr].size()!=3||koliko==1)
                return 0*printf("0\n");
            vector<int> vals;
            for(auto p:sinovi[tr])
                vals.pb(dep[p]);
            sort(all(vals));
            if(vals[0]!=vals[1]||vals[1]!=vals[2]-1)
                return 0*printf("0\n");
            koliko=1;
            sol=tr;
        }
        else
        {
            if(sinovi[tr].size()!=2&&sinovi[tr].size()!=0)
            {
                if(sinovi[tr].size()!=1||koliko==1)
                    return 0*printf("0\n");
                sol=tr;
                koliko=1;
            }
        }
        for(auto p:graf[tr])
        {
            degree[p]--;
            sinovi[p].pb(tr);
            if(degree[p]==1)
                leaf.push(p);
        }
    }
    if(sol==-1||cnt2!=m)
        return 0*printf("0\n");
    printf("1\n%i\n",sol);
    return 0;
}

/*bool test(int a)
{
    vector<int> ima(10);
    while(a)
    {
        int t=a%10;
        a/=10;
        if(ima[t])
            return 0;
        ima[t]=1;
    }
    return 1;
}
int main()
{
	int l,r;
	scanf("%i %i",&l,&r);
	for(int i=l;i<=r;i++)
        if(test(i))
            return 0*printf("%i\n",i);
    printf("-1\n");
    return 0;
}*/