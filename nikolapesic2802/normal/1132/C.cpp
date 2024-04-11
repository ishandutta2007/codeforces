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

int main()
{
	int n,q;
	scanf("%i %i",&n,&q);
	vector<pair<int,int> > p(q);
	for(int i=0;i<q;i++)
        scanf("%i %i",&p[i].f,&p[i].s),p[i].f--,p[i].s--;
    sort(all(p));
    vector<int> painted(n+1);
    int tr=0,r=-1;
    int best=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(i)
            painted[i]+=painted[i-1];
        while(p[tr].f<=i&&tr<q)
            painted[i]++,painted[p[tr].s+1]--,tr++;
        cnt+=painted[i]>0;
    }
    vector<int> cnt1(n),cnt2(n);
    cnt1[0]=painted[0]==1;
    cnt2[0]=painted[0]==2;
    for(int i=1;i<n;i++)
    {
        cnt1[i]=cnt1[i-1];
        cnt2[i]=cnt2[i-1];
        cnt1[i]+=painted[i]==1;
        cnt2[i]+=painted[i]==2;
    }
    for(int i=0;i<q;i++)
    {
        for(int j=i+1;j<q;j++)
        {
            if(p[i].s<p[j].f)
            {
                int sol=cnt-cnt1[p[i].s];
                if(p[i].f)
                    sol+=cnt1[p[i].f-1];
                sol-=cnt1[p[j].s];
                if(p[j].f)
                    sol+=cnt1[p[j].f-1];
                best=max(best,sol);
            }
            else
            {
                int sol=cnt;
                if(p[j].f>p[i].f)
                {
                    sol-=cnt1[p[j].f-1];
                    if(p[i].f)
                        sol+=cnt1[p[i].f-1];
                }
                if(p[i].s>p[j].s)
                {
                    sol-=cnt2[p[j].s];
                    if(p[j].f)
                        sol+=cnt2[p[j].f-1];
                    sol-=cnt1[p[i].s];
                    if(p[j].s)
                        sol+=cnt1[p[j].s-1];
                    best=max(best,sol);
                    continue;
                }
                sol-=cnt2[p[i].s];
                if(p[j].f)
                    sol+=cnt2[p[j].f-1];
                if(p[j].s>p[i].s)
                {
                    sol-=cnt1[p[j].s];
                    sol+=cnt1[p[i].s];
                }
                best=max(best,sol);
            }
        }
    }
    printf("%i\n",best);
    return 0;
}