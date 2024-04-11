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
	int n,a,b;
	scanf("%i %i %i",&n,&a,&b);
	map<int,int> ima;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
        scanf("%i",&arr[i]),ima[arr[i]]=i+1;
    vector<int> gde(n);
    vector<vector<int> > graf(n);
    vector<pair<int,int> > starts;
    for(int i=0;i<n;i++)
    {
        int c=0;
        if(ima[a-arr[i]]!=0)
        {
            if(ima[b-arr[i]]==0)
                starts.pb({i,0});
            c++;
            graf[i].pb(ima[a-arr[i]]-1);
        }
        if(ima[b-arr[i]]!=0)
        {
            if(ima[a-arr[i]]==0)
                starts.pb({i,1});
            c++;
            graf[i].pb(ima[b-arr[i]]-1);
        }
        if(c==0)
        {
            printf("NO\n");
            return 0;
        }
    }
    vector<int> visited(n);
    for(auto p:starts)
    {
        if(visited[p.f])
        {
            if(gde[p.f]!=p.s)
            {
                printf("NO\n");
                return 0;
            }
            continue;
        }
        queue<int> q;
        q.push(p.f);
        visited[p.f]=1;
        gde[p.f]=p.s;
        while(q.size())
        {
            int tr=q.front();
            q.pop();
            for(auto d:graf[tr])
            {
                if(visited[d])
                    continue;
                visited[d]=1;
                gde[d]=p.s;
                q.push(d);
            }
        }
    }
    printf("YES\n");
    for(int i=0;i<n;i++)
    {
        printf("%i ",gde[i]);
    }
    return 0;
}