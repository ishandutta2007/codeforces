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
	int n;
	scanf("%i",&n);
	vector<vector<int> > matrix(n,vector<int>(n));
	vector<int> cnt(1005);
	for(int i=0;i<n*n;i++)
    {
        int a;
        scanf("%i",&a);
        cnt[a]++;
    }
    int tr=1;
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++){
            while(cnt[tr]<4&&tr<1005)
                tr++;
            if(tr==1005)
            {
                printf("NO\n");
                return 0;
            }
            cnt[tr]-=4;
            matrix[i][j]=tr;
            matrix[n-i-1][j]=tr;
            matrix[i][n-j-1]=tr;
            matrix[n-i-1][n-j-1]=tr;
        }
    }
    if(n%2==1)
    {
        tr=1;
        for(int i=0;i<n/2;i++)
        {
            while(cnt[tr]<2&&tr<1005)
                tr++;
            if(tr==1005)
            {
                printf("NO\n");
                return 0;
            }
            cnt[tr]-=2;
            matrix[i][n/2]=tr;
            matrix[n-i-1][n/2]=tr;
        }
        for(int i=0;i<n/2;i++)
        {
            while(cnt[tr]<2&&tr<1005)
                tr++;
            if(tr==1005)
            {
                printf("NO\n");
                return 0;
            }
            cnt[tr]-=2;
            matrix[n/2][i]=tr;
            matrix[n/2][n-i-1]=tr;
        }
        tr=1;
        while(cnt[tr]==0)
            tr++;
        matrix[n/2][n/2]=tr;
        cnt[tr]--;
    }
    printf("YES\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%i ",matrix[i][j]);
        printf("\n");
    }
    return 0;
}