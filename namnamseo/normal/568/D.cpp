#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
struct line {
    long long a,b,c;
    line operator*(const line& other) const {
        return {b*other.c-c*other.b,c*other.a-a*other.c,a*other.b-b*other.a};
    }
    bool isCrossing(line& x){
        return a*x.a + b*x.b + c*x.c == 0;
    }
};

line ld[100010];

int pa[10];
int pb[10];
int used;

int ra=2,rb=197359,rp=222289;

int getRand(int val)
{
    ra=(1ll*ra*rb)%rp;
    return ra%val;
}

bool work(vector<int>& d,int k)
{
    if(d.empty()) return true;
    else if(k==0) return false;
    else if(d.size()<=k){
        int i;
        int sz=d.size();
        for(i=0;i<sz;++i){
            pa[used+i]=d[i]+1;
            pb[used+i]=-1;
        }
        used+=sz;
        return true;
    } else if(k==1){
        int sz=d.size();
        line a=ld[d[0]]*ld[d[1]];
        if(!a.c) return false;
        for(int _=2;_<sz;++_){
            if(!ld[d[_]].isCrossing(a)) return false;
        }
        pa[used]=d[0]+1;
        pb[used]=d[1]+1;
        ++used;
        return true;
    } else {
        int i,j,a,b,sz=d.size();
        line curc;
        vector<int> nxt;
        for(i=0;i<50;++i){
            a=getRand(sz);
            b=(a+1+getRand(sz-1))%sz;
            if(a==b){
                --i;
                continue;
            }
            curc=ld[d[a]]*ld[d[b]];
            if(curc.c){
                nxt.clear();
                for(j=0;j<sz;++j){
                    if(!ld[d[j]].isCrossing(curc)) nxt.push_back(d[j]);
                }
                if((sz-nxt.size())>=sz/k){
                    if(work(nxt,k-1)){
                        pa[used]=d[a]+1; pb[used]=d[b]+1; ++used;
                        return true;
                    } else return false;
                }
            } else --i;
        }
        return false;
    }
}

int main()
{
    int n,k;
    int i;
    int a,b,c;
    scanf("%d%d",&n,&k);
    vector<int> ini;
    for(i=0;i<n;++i) ini.push_back(i),scanf("%d%d%d",&a,&b,&c), ld[i]={a,b,c};
    if(work(ini,k)){
        puts("YES");
        printf("%d\n",used);
        for(i=0;i<used;++i) printf("%d %d\n",pa[i],pb[i]);
    } else puts("NO");
    return 0;
}