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
	int n,sum=0;
	scanf("%i",&n);
	vector<int> arr(n);
	for(int i=0;i<n;i++)
        scanf("%i",&arr[i]),sum+=arr[i];
    int m=0;
    for(int i=1;i<=sum;i++)
    {
        bool test=true;
        int c=0;
        for(int j=0;j<n;j++)
            if(arr[j]%i)
                test=false;
            else
            {
                if(i%2&&(arr[j]/i)%2)
                    c++;
            }
        if(test&&c<2)
            m=i;
    }
    if(m==0)
    {
        string sol;
        for(int i=0;i<n;i++)
            for(int j=0;j<arr[i];j++)
                sol+=('a'+i);
        printf("0\n");
        cout << sol << endl;
        return 0;
    }
    deque<int> sol;
    for(int i=0;i<n;i++)
        if((arr[i]/m)%2==1)
            sol.pb(i),arr[i]-=m;
    for(int i=0;i<n;i++)
        for(int j=0;j<arr[i]/m/2;j++)
            sol.pb(i),sol.push_front(i);
    string o;
    for(int i=0;i<m;i++)
    {
        if(i%2)
            for(int j=0;j<sol.size();j++)
                o+=sol[j]+'a';
        else
            for(int j=sol.size()-1;j>=0;j--)
                o+=sol[j]+'a';
    }
    printf("%i\n",m);
    cout << o << endl;
    return 0;
}