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

const int N=512;
vector<int> cnt(N);
vector<vector<pair<int,int> > > pice(N);
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=0;i<n;i++)
    {
        int k;
        scanf("%i",&k);
        int mask=0;
        for(int j=0;j<k;j++)
        {
            int d;
            scanf("%i",&d);
            d--;
            mask+=(1<<d);
        }
        cnt[mask]++;
    }
    for(int i=0;i<m;i++)
    {
        int p,k;
        scanf("%i %i",&p,&k);
        int mask=0;
        for(int j=0;j<k;j++)
        {
            int d;
            scanf("%i",&d);
            d--;
            mask+=(1<<d);
        }
        pice[mask].pb({p,i});
    }
    for(int j=0;j<N;j++)
    {
        sort(all(pice[j]));
        while(pice[j].size()>2)
            pice[j].pop_back();
    }
    int maxx=-1,pr=0;
    int a,b;
    for(int i=0;i<N;i++)
    {
        if(pice[i].empty())
            continue;
        for(int j=0;j<N;j++)
        {
            if(pice[j].empty())
                continue;
            int price=0,p1,p2;
            if(i==j)
            {
                if(pice[i].size()<2)
                    continue;
                price=pice[i][0].f+pice[i][1].f;
                p1=pice[i][0].s;p2=pice[i][1].s;
            }
            else
            {
                price=pice[i][0].f+pice[j][0].f;
                p1=pice[i][0].s;
                p2=pice[j][0].s;
            }
            int com=i|j;
            int number=0;
            for(int k=com;k;k=(k-1)&com)
                number+=cnt[k];
            if(number>maxx)
                maxx=number,pr=price,a=p1,b=p2;
            if(maxx==number)
            {
                if(price<pr)
                    pr=price,a=p1,b=p2;
            }
        }
    }
    printf("%i %i\n",a+1,b+1);
    return 0;
}