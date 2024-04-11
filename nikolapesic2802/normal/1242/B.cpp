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

const int N=1e5+5;
map<int,int> edge[N];
set<int> ne;
int cnt=-1;
int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    for(int i=0;i<n;i++)
        ne.insert(i);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a][b]=1;
        edge[b][a]=1;
    }
    while(ne.size())
    {
        int tr=*ne.begin();
        cnt++;
        ne.erase(ne.begin());
        vector<int> uzet;
        queue<int> q;
        q.push(tr);
        while(q.size())
        {
            int tr=q.front();
            q.pop();
            auto it=ne.begin();
            while(it!=ne.end())
            {
                int t=*it;
                if(edge[t][tr])
                {
                    it++;
                    continue;
                }
                auto it2=it;
                it2++;
                q.push(t);
                ne.erase(it);
                it=it2;
            }
        }
    }
    printf("%i\n",cnt);
    return 0;
}