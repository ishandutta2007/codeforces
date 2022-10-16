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
int segment(int x,int y)
{
    if(x<500)
    {
        if(y<500)
            return 1;
        return 2;
    }
    if(y<500)
        return 3;
    return 4;
}
vector<pair<int,int> > r(666);
void check(int x,int y)
{
    for(auto p:r)
        if(p.f==x||p.s==y)
            exit(0);
}
bool ima(int x,int y)
{
    for(auto p:r)
        if(p.f==x&&p.s==y)
            return true;
    return false;
}
int main()
{

	int x,y;
	scanf("%i %i",&x,&y);
	for(int i=0;i<666;i++)
        scanf("%i %i",&r[i].f,&r[i].s);
    while(x<500)
    {
        x++;
        printf("%i %i\n",x,y);
        fflush(stdout);
        check(x,y);
        int k;
        scanf("%i",&k);
        scanf("%i %i",&r[k-1].f,&r[k-1].s);
    }
    while(x>500)
    {
        x--;
        printf("%i %i\n",x,y);
        fflush(stdout);
        check(x,y);
        int k;
        scanf("%i",&k);
        scanf("%i %i",&r[k-1].f,&r[k-1].s);
    }
    while(y<500)
    {
        y++;
        printf("%i %i\n",x,y);
        fflush(stdout);
        check(x,y);
        int k;
        scanf("%i",&k);
        scanf("%i %i",&r[k-1].f,&r[k-1].s);
    }
    while(y>500)
    {
        y--;
        printf("%i %i\n",x,y);
        fflush(stdout);
        check(x,y);
        int k;
        scanf("%i",&k);
        scanf("%i %i",&r[k-1].f,&r[k-1].s);
    }
    vector<int> cnt(4);
    for(int i=0;i<666;i++)
        cnt[segment(r[i].f,r[i].s)-1]++;
    int m=min(min(cnt[0],cnt[1]),min(cnt[2],cnt[3]));
    int dx,dy;
    if(m==cnt[0])
        dx=1,dy=1;
    if(m==cnt[1])
        dx=1,dy=-1;
    if(m==cnt[2])
        dx=-1,dy=1;
    if(m==cnt[3])
        dx=-1,dy=-1;
    for(int i=0;i<499;i++)
    {
        if(ima(x+dx,y+dy))
        {
            printf("%i %i\n",x+dx,y);
            fflush(stdout);
            return 0;
        }
        x+=dx;
        y+=dy;
        printf("%i %i\n",x,y);
        fflush(stdout);
        int k;
        scanf("%i",&k);
        scanf("%i %i",&r[k-1].f,&r[k-1].s);
    }
    return 0;
}