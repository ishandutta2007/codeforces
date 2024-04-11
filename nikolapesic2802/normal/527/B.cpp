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

vector<vector<int> > index(26,vector<int>(26,-1));
int main()
{
	int n;
	scanf("%i",&n);
	string s,t;
	cin >> s >> t;
	int dist=0;
	pair<int,int> sol={-1,-1};
	vector<int> imam(26,-1),treba(26,-1);
	pair<int,int> sol2={-1,-1};
	for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            int a=s[i]-'a';
            int b=t[i]-'a';
            if(index[b][a]!=-1)
                sol={index[b][a]+1,i+1};
            if(imam[b]!=-1)
                sol2={imam[b]+1,i+1};
            if(treba[a]!=-1)
                sol2={treba[a]+1,i+1};
            imam[a]=i;
            treba[b]=i;
            index[a][b]=i;
            dist++;
        }
    }
    if(sol.f!=-1)
    {
        printf("%i\n",dist-2);
        printf("%i %i\n",sol.f,sol.s);
        return 0;
    }
    if(sol2.f!=-1)
    {
        printf("%i\n",dist-1);
        printf("%i %i\n",sol2.f,sol2.s);
        return 0;
    }
    printf("%i\n-1 -1\n",dist);
    return 0;
}