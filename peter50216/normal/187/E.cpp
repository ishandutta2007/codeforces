#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int n,lt,rt,s;
int di[101000];
int dd[101000];
const long long INF=10000000000000000ll;
long long ans=INF;
int aid[101000];
int tid[101000],tt;
bool flag;
bool ansf;
long long ta;
inline void cl(){tt=0;}
inline void pp(int x){tid[tt++]=x;}
inline void tr(){
    //for(int i=0;i<tt;i++)printf("%d ",tid[i]);
   // puts("");
    if(ta<ans){
        ans=ta;
        ansf=flag;
        for(int i=0;i<n-1;i++)aid[i]=tid[i];
    }
}
pair<int,int> ev[101000];
int to[101000];
bool rev[101000];
inline void trylr(){
    if(s==n-1)return;
    if(rt==0)return;
    int i,j;
    if(lt==0){
        if(s!=0)return;
        cl();
        for(i=1;i<n;i++)pp(i);
        ta=(long long)di[n-1]-di[0];
        tr();
        return;
    }
    if(lt<=s){
        //puts("Case 1");
        cl();
        for(i=lt-1;i>=0;i--)pp(i);
        for(i=lt;i<s;i++)pp(i);
        for(i=s+1;i<n;i++)pp(i);
        ta=(long long)di[n-1]-di[0]+(long long)di[s]-di[0];
        tr();
        return;
    }else if(rt==1){
        cl();
        for(i=s-1;i>=0;i--)pp(i);
        for(i=n-1;i>s;i--)pp(i);
        ta=(long long)di[s]-di[0]+(long long)di[n-1]-di[0]+(long long)di[n-1]-di[s+1];
        tr();
        return;
    }else{
        int mo=lt-s;
        int evc=0;
        for(i=s+1;i<n-1;i++){
            ev[evc++]=make_pair(dd[i],i);
        }
        sort(ev,ev+evc);
        for(i=0;i<evc;i++)to[ev[i].second]=i;
        long long ss=0;
        int bi=-1;
        long long ba=INF;
        set<int> XD;
        set<int>::iterator pt;
        for(i=s+1;i<n-mo-1;i++){
            XD.insert(to[i]);
        }
        for(i=n-mo-1;i<n;i++){
            //printf("i=%d ss=%I64d\n",i,ss);
            if(ba>ss*2+di[n-1]-di[i]){
                ba=ss*2+di[n-1]-di[i];
                bi=i;
            }
            int toa=i-1;
            if(i==n-mo-1){
                XD.insert(to[toa]);
                pt=XD.begin();
                ss+=ev[*pt].first;
            }else{
                if(to[toa]<*pt){
                    ss+=ev[to[toa]].first;
                }else{
                    XD.insert(to[toa]);
                    pt++;
                    ss+=ev[*pt].first;
                }
            }
        }
        //printf("ba=%I64d bi=%d\n",ba,bi);
        ta=(long long)di[s]-di[0]+(long long)di[n-1]-di[0]+ba;
        cl();
        for(i=s-1;i>=0;i--)pp(i);
        memset(rev,0,sizeof(rev));
        XD.clear();
        for(i=s+1;i<n-mo-1;i++){
            XD.insert(to[i]);
        }
        for(i=n-mo;i<=bi;i++){
            int toa=i-1;
            if(i==n-mo){
                XD.insert(to[toa]);
                pt=XD.begin();
                rev[ev[*pt].second]=1;
            }else{
                if(to[toa]<*pt){
                    rev[toa]=1;
                }else{
                    XD.insert(to[toa]);
                    pt++;
                    rev[ev[*pt].second]=1;
                }
            }
        }
        for(i=s+1;i<bi;i=j+1){
            for(j=i;j<bi-1&&rev[j];j++);
            for(int q=j;q>=i;q--)pp(q);
        }
        for(i=n-1;i>=bi;i--){
            pp(i);
        }
        tr();
    }
}
inline void tryrl(){
    //puts("tryrl");
    swap(lt,rt);
    s=n-1-s;
    int i,j;
    int l=di[n-1];
    for(i=0;i<n;i++){
        di[i]=l-di[i];
    }
    for(i=0,j=n-1;i<j;i++,j--)swap(di[i],di[j]);
    for(i=0;i<n-1;i++)dd[i]=di[i+1]-di[i];
    flag=1;
    trylr();
}
int main(){
    int i,j,k;
    scanf("%d%d%d",&n,&lt,&s);
    rt=n-1-lt;
    s--;
    for(i=0;i<n;i++)scanf("%d",&di[i]);
    for(i=0;i<n-1;i++)dd[i]=di[i+1]-di[i];
    flag=0;
    trylr();
    tryrl();
    if(ans==INF)puts("-1");
    else{
        printf("%I64d\n",ans);
        for(i=0;i<n-1;i++)printf("%d%c",ansf?n-aid[i]:aid[i]+1,(i==n-2?'\n':' '));
    }
}