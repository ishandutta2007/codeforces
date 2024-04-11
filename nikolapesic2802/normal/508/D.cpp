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

vector<pair<char,char> > graf[255][255];
int in[255][255];
int out[255][255];
string sol;
int st[255][255];
void solve(char i,char j)
{
    for(;st[i][j]<(int)graf[i][j].size();)
    {
        pair<int,int> p=graf[i][j][st[i][j]];
        st[i][j]++;
        solve(p.f,p.s);
    }
    sol+=j;
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        graf[s[0]][s[1]].pb({s[1],s[2]});
        out[s[0]][s[1]]++;
        in[s[1]][s[2]]++;
    }
    pair<int,int> start={-1,-1};
    int cnt=0;
    for(int i=0;i<255;i++)
        for(int j=0;j<255;j++){
            if(in[i][j]!=out[i][j])
            {
                cnt++;
                if(abs(in[i][j]-out[i][j])!=1)
                {
                    printf("NO\n");
                    return 0;
                }
                if(in[i][j]<out[i][j])
                    start={i,j};
            }
            else
                if(in[i][j]+out[i][j]>0&&start==make_pair(-1,-1))
                    start={i,j};
        }
    if(cnt>2)
    {
        printf("NO\n");
        return 0;
    }
    solve(start.f,start.s);
    sol+=start.f;
    reverse(all(sol));
    if(sol.size()!=n+2)
    {
        printf("NO\n");
        return 0;
    }
    cout << "YES" << endl << sol << endl;
    return 0;
}