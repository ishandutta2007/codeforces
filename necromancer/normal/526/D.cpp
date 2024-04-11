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

#define MAXN 2000010

void exKMP(char* a, char * b, int M, int N, int *Next, int *ret) {
    int i,j,k;
    for(j=0;1+j<M&&a[j]==a[1+j];j++);
    Next[1]=j;
    k=1;
    for(i=2;i<M;i++) {
        int Len=k+Next[k], L=Next[i-k];
        if(L<Len-i) Next[i]=L;
        else{
            for(j=max(0,Len-i);i+j<M&&a[j]==a[i+j];j++);
            Next[i]=j;
            k=i;
        }
    }
    for(j=0;j<N&&j<M&&a[j]==b[j];j++);
    ret[0]=j;
    k=0;
    for(int i=1;i<N;i++){
        int Len=k+ret[k],L=Next[i-k];
        if(L<Len-i){
            ret[i]=L;
        }else{
            for(j=max(0,Len-i);j<M&&i+j<N&&a[j]==b[i+j];j++);
            ret[i]=j;
            k=i;
        }
    }
}

char s[MAXN];
int nxt[MAXN];
int ret[MAXN];

ll cov[MAXN];

char ans[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    cin>>s;
    exKMP(s,s,n,n,nxt,ret);
    if(k==1) cov[0]=1;
    
    REP(i,n) if(i){
        int c = ret[i]/i + 1;
        if(c >= k) {
            cov[i*k-1]++;
            cov[min(i*(k+1), i+ret[i])]--;
        }
    }
    REP(i,n) {
        if(i) cov[i]+=cov[i-1];
        if(cov[i]) ans[i]='1';
        else ans[i]='0';
    }
    cout<<ans<<endl;
    return 0;
}