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

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int m,a,b;
    scanf("%i %i %i",&m,&a,&b);
    int g=gcd(a,b);
    int granica=2e5+5;
    vector<int> moze(granica+1);
    int cnt=1;
    moze[0]=1;
    ll sol=1;
    for(int i=1;i<=min(granica,m);i++)
    {
        if(i-a>=0&&moze[i-a])
        {
            moze[i]=1;
            queue<int> q;
            q.push(i);
            while(q.size())
            {
                int tr=q.front();
                q.pop();
                cnt++;
                if(tr-b>=0&&!moze[tr-b])
                {
                    moze[tr-b]=1;
                    q.push(tr-b);
                }
                if(tr+a<i&&!moze[tr+a])
                {
                    moze[tr+a]=1;
                    q.push(tr+a);
                }
            }
        }
        sol+=cnt;
    }
    if(granica>=m)
    {
        printf("%lld\n",sol);
        return 0;
    }
    granica++;
    while(granica<=m&&granica%g!=0)
    {
        sol+=granica/g+1;
        granica++;
    }
    while(granica<=m&&m%g!=0)
    {
        sol+=m/g+1;
        m--;
    }
    if(granica>m)
    {
        printf("%lld\n",sol);
        return 0;
    }
    sol+=m/g+1;
    m--;
    int dist=m-granica+1;
    assert(dist%g==0);
    int koliko=dist/g;
    sol+=(ll)koliko*(koliko+1)/2*g;
    sol+=(ll)granica/g*dist;
    printf("%lld\n",sol);
    return 0;
}