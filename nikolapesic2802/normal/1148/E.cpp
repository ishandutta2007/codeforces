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
	int n;
	scanf("%i",&n);
	vector<pair<int,int> > a(n),b(n);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i].f),a[i].s=i;
    for(int i=0;i<n;i++)
        scanf("%i",&b[i].f),b[i].s=i;
    sort(all(a));
    sort(all(b));
    ll sum=0;
    vector<pair<int,pair<int,int> > > smanji,povecaj;
    for(int i=0;i<n;i++){
        sum+=b[i].f-a[i].f;
        if(b[i].f>a[i].f)
            povecaj.pb({a[i].f,{b[i].f-a[i].f,i}});
        if(b[i].f<a[i].f)
            smanji.pb({a[i].f,{a[i].f-b[i].f,i}});
    }
    if(sum!=0)
    {
        printf("NO\n");
        return 0;
    }
    sort(all(smanji));
    sort(all(povecaj));
    //cout << smanji << povecaj << endl;
    int i=0,j=0;
    vector<pair<pair<int,int>,int> > change;
    while(i<smanji.size()&&j<povecaj.size())
    {
        int k=min(smanji[i].s.f,povecaj[j].s.f);
        smanji[i].s.f-=k;
        povecaj[j].s.f-=k;
        change.pb({{a[povecaj[j].s.s].s,a[smanji[i].s.s].s},k});
        //printf("%i %i\n",a[povecaj[j].s.s].f,a[smanji[i].s.s].f);
        if(a[smanji[i].s.s].f-a[povecaj[j].s.s].f<2*k)
        {
            printf("NO\n");
            return 0;
        }
        a[povecaj[j].s.s].f+=k;
        a[smanji[i].s.s].f-=k;
        if(smanji[i].s.f==0)
            i++;
        if(povecaj[j].s.f==0)
            j++;
    }
    if(i==smanji.size()&&j==povecaj.size()){
        printf("YES\n");
        printf("%i\n",change.size());
        for(auto p:change)
            printf("%i %i %i\n",p.f.f+1,p.f.s+1,p.s);
        return 0;
    }
    else
    {
        printf("NO\n");
        return 0;
    }
}