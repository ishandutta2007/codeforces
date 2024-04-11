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
	int t;
	scanf("%i",&t);
	while(t--)
    {
        int n,k;
        scanf("%i %i",&n,&k);
        string s;
        cin >> s;
        auto rev=[&](int l,int r){
            for(int i=l;i<=(l+r)/2;i++)
                swap(s[i],s[r-i+l]);
        };
        int izostavi=n/2-k+1;
        printf("%i\n",n);
        for(int i=0;i<izostavi;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(s[j]=='(')
                {
                    printf("%i %i\n",i+1,j+1);
                    rev(i,j);
                    break;
                }
            }
        }
        for(int i=izostavi;i<2*izostavi;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(s[j]==')')
                {
                    printf("%i %i\n",i+1,j+1);
                    rev(i,j);
                    break;
                }
            }
        }
        for(int i=2*izostavi;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i&1)
                {
                    if(s[j]==')')
                    {
                        printf("%i %i\n",i+1,j+1);
                        rev(i,j);
                        break;
                    }
                }
                else
                {
                    if(s[j]=='(')
                    {
                        printf("%i %i\n",i+1,j+1);
                        rev(i,j);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}