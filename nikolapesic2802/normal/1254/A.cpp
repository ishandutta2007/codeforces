#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string slo;
	for(char c='a';c<='z';c++)
        slo+=c;
    for(char c='A';c<='Z';c++)
        slo+=c;
    for(char c='0';c<='9';c++)
        slo+=c;
	int t;
	scanf("%i",&t);
	while(t--)
    {
        int n,m,k;
        scanf("%i %i %i",&n,&m,&k);
        vector<string> mat(n);
        for(int i=0;i<n;i++)
            cin >> mat[i];
        int cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]=='R')
                    cnt++;
        int sl=cnt/k,os=cnt%k;
        int i=0,j=0;
        string out;
        for(int o=0;i<n;o++)
        {
            int tr=0;
            while((tr<sl+(os>o?1:0)&&i<n)||(o==k-1&&i<n))
            {
                out+=slo[o];
                if(mat[i][j]=='R')
                    tr++;
                if(i%2)
                {
                    j--;
                    if(j==-1)
                    {
                        j++;
                        i++;
                        reverse(all(out));
                        cout << out << endl;
                        out="";
                    }
                }
                else{
                    j++;
                    if(j==m)
                    {
                        j--;
                        i++;
                        cout << out << endl;
                        out="";
                    }
                }
            }
        }
    }
    return 0;
}