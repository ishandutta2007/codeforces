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

const int N=1e5,L=60;
int t[4*N][L];
void update(int i)
{
    for(int j=0;j<L;j++)
        t[i][j]=t[2*i][j]+t[2*i+1][(t[2*i][j]+j)%L];
}
void sett(int pos,int val,int l=0,int r=N-1,int i=1)
{
    if(l>pos||r<pos)
        return;
    if(l==pos&&r==pos)
    {
        for(int j=0;j<L;j++)
        {
            t[i][j]=1;
            if(j%val==0)
                t[i][j]++;
        }
        return;
    }
    int m=(l+r)>>1;
    sett(pos,val,l,m,2*i);
    sett(pos,val,m+1,r,2*i+1);
    update(i);
}
int getTime(int qs,int qe,int ti=0,int l=0,int r=N-1,int i=1)
{
    if(qs>r||qe<l)
        return 0;
    if(qs<=l&&qe>=r)
        return t[i][ti];
    int m=(l+r)>>1;
    int le=getTime(qs,qe,ti,l,m,2*i);
    return le+getTime(qs,qe,(ti+le)%L,m+1,r,2*i+1);
}
int main()
{
    int n;
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        sett(i,a);
    }
    int q;
    scanf("%i",&q);
    for(int i=0;i<q;i++)
    {
        char s[2];
        int x,y;
        scanf("%s %i %i",s,&x,&y);
        if(s[0]=='C')
            sett(x-1,y);
        else
            printf("%i\n",getTime(x-1,y-2));
    }
    return 0;
}