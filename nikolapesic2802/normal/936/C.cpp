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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
string a,t;
void shift(int x)
{
    string alfa=a.substr(0,a.size()-x);
    string beta=a.substr(a.size()-x,x);
    reverse(all(beta));
    a=beta+alfa;
}
bool test()
{
    string aa=a,tt=t;
    sort(all(aa));
    sort(all(tt));
    return aa==tt;
}
int main()
{
    /*for(int i=0;i<7;i++)
        a+='a'+i;
    cout << a << endl;
    while(true)
    {
        int aa;
        scanf("%i",&aa);
        shift(aa);
        cout << a << endl;
    }*/
    int n;
    scanf("%i",&n);
    cin >> a >> t;
    if(!test())
    {
        printf("-1\n");
        return 0;
    }
    vector<char> order;
    int tr=(n-1)/2;
    int offset=1;
    order.pb(t[tr]);
    while(tr+offset<n)
    {
        order.pb(t[tr+offset]);
        if(tr-offset>=0)
            order.pb(t[tr-offset]);
        offset++;
    }
    //cout << order;
    vector<int> operacije;
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=1;j<=n;j++)
            if(a[n-j]==order[i])
                break;
        shift(j);
        shift(n-i-j);
        shift(n);
        operacije.pb(j);
        operacije.pb(n-i-j);
        operacije.pb(n);
    }
    if(n%2==1)
        operacije.pb(n),shift(n);
    assert(a==t);
    printf("%i\n",operacije.size());
    for(auto p:operacije)
        printf("%i ",p);
    return 0;
}