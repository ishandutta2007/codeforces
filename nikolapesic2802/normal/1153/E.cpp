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

bool ask(int x1,int y1,int x2,int y2)
{
    printf("? %i %i %i %i\n",x1,y1,x2,y2);
    fflush(stdout);
    int a;
    scanf("%i",&a);
    return a%2==1;
}
int main()
{
    int n;
    scanf("%i",&n);
    int c1=-1,c2=-1;
    for(int i=1;i<n;i++)
    {
        int t=ask(1,1,n,i);
        if(t)
        {
            if(c1==-1)
                c1=i;
        }
        else
        {
            if(c1!=-1)
            {
                c2=i;
                break;
            }
        }
    }
    if(c1!=-1)
    {
        if(c2==-1)
            c2=n;
        int l=1,r=n;
        while(l<r)
        {
            int m=(l+r)>>1;
            int t=ask(1,c1,m,c1);
            if(t)
                r=m;
            else
                l=m+1;
        }
        int l1=1,r1=n;
        while(l1<r1)
        {
            int m=(l1+r1)>>1;
            int t=ask(1,c2,m,c2);
            if(t)
                r1=m;
            else
                l1=m+1;
        }
        printf("! %i %i %i %i\n",l,c1,l1,c2);
        return 0;
    }
    c1=c2=-1;
    for(int i=1;i<n;i++)
    {
        int t=ask(1,1,i,n);
        if(t)
        {
            if(c1==-1)
                c1=i;
        }
        else
        {
            if(c1!=-1)
            {
                c2=i;
                break;
            }
        }
    }
    assert(c1!=-1);
    if(c1!=-1)
    {
        if(c2==-1)
            c2=n;
        int l=1,r=n;
        while(l<r)
        {
            int m=(l+r)>>1;
            int t=ask(c1,1,c1,m);
            if(t)
                r=m;
            else
                l=m+1;
        }
        int l1=1,r1=n;
        while(l1<r1)
        {
            int m=(l1+r1)>>1;
            int t=ask(c2,1,c2,m);
            if(t)
                r1=m;
            else
                l1=m+1;
        }
        printf("! %i %i %i %i\n",c1,l,c2,l1);
        return 0;
    }
    return 0;
}