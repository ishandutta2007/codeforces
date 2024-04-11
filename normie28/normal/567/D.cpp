#include <bits/stdc++.h>
using namespace std;
 
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define MOD 1000000007
#define  F  first
#define  S  second
#define  pb push_back
#define  mp make_pair
typedef long long int ll;
const int N = 1e6+6,inf = 1e9+7;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,a;cin>>n>>k>>a;
    int m;cin>>m;
    set<int>st;
    st.insert(0);
    st.insert(n+1);
    int cur = (n+1)/(a+1);
    for(int i=1;i<=m;i++)
    {
        int x;cin>>x;
        auto it = st.lower_bound(x);
        int rgt = *it;
        it--;
        int lft = *it;
        it++;
        cur -= (rgt-lft)/(a+1);
        cur += (x-lft)/(a+1);
        cur += (rgt-x)/(a+1);
        if(cur<k)
            cout<<i<< "\n",exit(0);
        st.insert(x);
    }
    cout<< "-1\n";
}