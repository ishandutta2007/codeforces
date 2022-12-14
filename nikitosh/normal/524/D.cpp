#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>

#include<iostream>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<deque>
using namespace std;

#ifdef WIN32
    #define lld "%I64d"
    #define llu "%I64u"
#else
    #define lld "%lld"
    #define llu "%llu"
#endif

typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define forn(i,n) for(int i=0;i<(n);++i)
#define fornr(i,n) for(int i=(n)-1;i>=0;--i)
#define forab(i,a,b) for(int i=(a);i<(b);++i)
#define forba(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define forit(i,A) for(__typeof((A).begin()) i=(A).begin();i!=(A).end();++i)
#define all(A) (A).begin(),(A).end()

const int MAX=2e5;
vector< pair<int,pii> > Ev;
vi V;
int Id[MAX], Cnt[MAX];

int main(){
    //assert(freopen("1.in","r",stdin));
    //assert(freopen("1.out","w",stdout));

    int N,M,T;
    scanf("%d%d%d",&N,&M,&T);
    forn(i,N){
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        int z=(h*60+m)*60+s;
        Ev.pb(mp(z,mp(1,i))), Ev.pb(mp(z+T,mp(-1,i)));
    }
    sort(all(Ev));
    
    int z=1,bal=0;
    bool ok=0;
    for(int i=0;i<(int)Ev.size();++i){
        int q=Ev[i].snd.snd;

        if(Ev[i].snd.fst==1){
            if(bal<M)
                V.pb(z++), Id[q]=z-1, ++Cnt[z-1];
            else
                V.pb(z-1), Id[q]=z-1, ok=1, ++Cnt[z-1];
            if(Cnt[z-1]==1)
                ++bal;
            if (bal == M)
                ok = 1;
        }else if((--Cnt[Id[q]])==0)
            --bal;

    }
    if(!ok)
        puts("No solution");
    else{
        printf("%d\n",z-1);
        forit(i,V)
            printf("%d\n",*i);
    }

    return 0;
}