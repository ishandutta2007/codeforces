
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

const int N=201,oo=INT_MIN/2,no=INT_MIN/3;;
int dp[N][N][3][3],aa[N][N][3][3],bb[N][N][3][3];
int calc(int a,int b,int c,int d)
{
    if(a<0||b<0)
        return no;
    if(a==0&&b==0)
    {
        if(c==3||d==3)
            return c-d;
        return no;
    }
    if(c==3||d==3)
        return no;
    if(dp[a][b][c][d]!=oo)
        return dp[a][b][c][d];
    dp[a][b][c][d]=no;
    int l=25,tr;
    if(c+d==4)
        l-=10;
    for(int i=0;i<l-1;i++)
    {
        if((tr=calc(a-l,b-i,c+1,d))>dp[a][b][c][d])
        {
            aa[a][b][c][d]=l;
            bb[a][b][c][d]=i;
            dp[a][b][c][d]=tr;
        }
        if((tr=calc(a-i,b-l,c,d+1))>dp[a][b][c][d])
        {
            aa[a][b][c][d]=i;
            bb[a][b][c][d]=l;
            dp[a][b][c][d]=tr;
        }
    }
    for(int i=l+1;i<N;i++)
    {
        if((tr=calc(a-i+2,b-i,c,d+1))>dp[a][b][c][d])
        {
            aa[a][b][c][d]=i-2;
            bb[a][b][c][d]=i;
            dp[a][b][c][d]=tr;
        }
        if((tr=calc(a-i,b-i+2,c+1,d))>dp[a][b][c][d])
        {
            aa[a][b][c][d]=i;
            bb[a][b][c][d]=i-2;
            dp[a][b][c][d]=tr;
        }
    }
    return dp[a][b][c][d];
}
int main()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<3;k++)
                for(int l=0;l<3;l++)
                    dp[i][j][k][l]=oo;
    int n;
    scanf("%i",&n);
    while(n--)
    {
        int a,b,c=0,d=0;
        scanf("%i %i",&a,&b);
        if(calc(a,b,c,d)==no)
            printf("Impossible\n");
        else
        {
            vector<pair<int,int> > setovi;
            while(a!=0||b!=0)
            {
                int da=aa[a][b][c][d],db=bb[a][b][c][d];
                if(da>db)
                    c++;
                else
                    d++;
                setovi.pb({da,db});
                a-=da;
                b-=db;
            }
            printf("%i:%i\n",c,d);
            for(auto p:setovi)
                printf("%i:%i ",p.f,p.s);
            printf("\n");
        }
    }
}