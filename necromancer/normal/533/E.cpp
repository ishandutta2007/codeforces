#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

int main()
{
    ios::sync_with_stdio(false);
    int n;
    string s1,s2;
    cin>>n;
    cin>>s1>>s2;
    VI v;
    for(int i=0;i<n;i++) {
        if(s1[i]!=s2[i]) {
            v.PB(i);
        }
    }
    int t=v.size();
    if(t==1) {
        cout<<2<<endl;
    }else{
        int l=v[0], r=v[v.size()-1];
        set<string> mp;
        string ss1=s1.substr(l,r-l+1), ss2=s2.substr(l,r-l+1);
        if(ss2[0]+ss1==ss2+ss1[ss1.size()-1])
            mp.insert(ss2[0]+ss1);
        if(ss1[0]+ss2==ss1+ss2[ss2.size()-1])
            mp.insert(ss1[0]+ss2);
        cout<<mp.size()<<endl;
    }
    return 0;
}