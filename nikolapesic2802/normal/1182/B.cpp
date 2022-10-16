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

int h,w;
bool inside(int x,int y)
{
    return x>=0&&x<h&&y>=0&&y<w;
}
int main()
{

	scanf("%i %i",&h,&w);
	vector<string> mat(h);
	for(int i=0;i<h;i++)
        cin >> mat[i];
    vector<int> sum(h),sumr(w);
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
            if(mat[i][j]=='*')
                sum[i]++;
    }
    for(int j=0;j<w;j++)
        for(int i=0;i<h;i++)
            if(mat[i][j]=='*')
                sumr[j]++;
    int x=-1,y=-1;
    for(int i=0;i<h;i++)
    {
        if(sum[i]>1)
        {
            if(x!=-1)
            {
                printf("NO\n");
                return 0;
            }
            x=i;
        }
    }
    for(int i=0;i<w;i++)
    {
        if(sumr[i]>1)
        {
            if(y!=-1)
            {
                printf("NO\n");
                return 0;
            }
            y=i;
        }
    }
    if(x==-1||y==-1)
    {
        printf("NO\n");
        return 0;
    }
    int cnt=3;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            if(mat[i][j]=='*')
                cnt++;
    int xx=x,yy=y;
    while(inside(xx,yy)&&mat[xx][yy]=='*')
        cnt--,xx--;
    xx=x;
    while(inside(xx,yy)&&mat[xx][yy]=='*')
        cnt--,xx++;
    xx=x;
    while(inside(xx,yy)&&mat[xx][yy]=='*')
        cnt--,yy--;
    yy=y;
    while(inside(xx,yy)&&mat[xx][yy]=='*')
        cnt--,yy++;
    yy=y;
    bool yes=inside(xx-1,yy)&&mat[xx-1][yy]=='*'&&inside(xx+1,yy)&&mat[xx+1][yy]=='*'&&inside(xx,yy-1)&&mat[xx][yy-1]=='*'&&inside(xx,yy+1)&&mat[xx][yy+1]=='*';
    if(cnt==0&&yes)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}