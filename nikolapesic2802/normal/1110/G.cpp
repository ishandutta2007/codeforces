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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
void test()
{
    int n;
    scanf("%i",&n);
    vector<vector<int> > graf(4*n);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    char c[n];
    scanf("%s",c);
    int lim=n;
    for(int i=0;i<lim;i++)
    {
        if(c[i]=='W')
        {
            graf[i].pb(n);
            graf[n].pb(i);
            graf[n].pb(n+1);
            graf[n+1].pb(n);
            graf[n].pb(n+2);
            graf[n+2].pb(n);
            n+=3;
        }
    }
    int cc=0;
    for(int i=0;i<n;i++)
    {
        if(graf[i].size()>3)
        {
            printf("White\n");
            return;
        }
        if(graf[i].size()==3)
            cc++;
        int cnt=0;
        for(auto p:graf[i])
            if(graf[p].size()>1)
                cnt++;
        if(cnt>=2&&graf[i].size()==3)
        {
            printf("White\n");
            return;
        }
    }
    assert(cc<=2);
    if(cc==2)
    {
        if(n%2==1)
        {
            printf("White\n");
            return;
        }
    }
    printf("Draw\n");
}

int main()
{
    int t;
    scanf("%i",&t);
    for(int i=1;i<=t;i++){
        test();
    }
    return 0;
}