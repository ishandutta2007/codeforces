#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
struct MC{
long long tm;
bool simple;
};
struct MC3{
int ctA;
int ctB;
};
bool cmp(const MC& MC1, const MC &MC2){
return MC1.tm<MC2.tm;
}
MC c[200002];
MC3 dp[200001];

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    dp[0].ctA=0;
    dp[0].ctB=0;
    for(int i=0;i<t;++i){
        long long n,a,b,T;
        cin>>n>>T>>a>>b;
        c[n+1].tm=T;
        int ctA=0, ctB=0;
        for(int i=1;i<=n;++i){
            int tmp;
            cin>>tmp;
            if(tmp==0){
                c[i].simple=true;
                ++ctA;
            }
            else {
                c[i].simple=false;
                ++ctB;
            }
        }
        for(int i=1;i<=n;++i)cin>>c[i].tm;
        int res=0;
        if((long long)a*ctA+(long long)b*ctB<=(long long)T){
            cout<<n<<"\n";
            continue;
        }
        sort(c+1,c+1+n,cmp);
        int rememb=c[1].tm;
        for(int i=1;i<=n;++i){
            if(c[i].simple){
                dp[i].ctA=dp[i-1].ctA+1;
                dp[i].ctB=dp[i-1].ctB;
            }
            else {
               dp[i].ctA=dp[i-1].ctA;
                dp[i].ctB=dp[i-1].ctB+1;
            }
            if(i!=n&&c[i].tm==c[i+1].tm)continue;
            if((long long)dp[i].ctA*a+dp[i].ctB*b>(long long)c[i+1].tm-1)c[i].tm=-1;
            else { c[i].tm=c[i+1].tm-1-dp[i].ctA*a-dp[i].ctB*b;
            }
            if(c[i].tm>=0){
                int tm=dp[i].ctA+dp[i].ctB;
                int TMPA=ctA-dp[i].ctA,TMPB=ctB-dp[i].ctB;
                int TMP=c[i].tm/a;
                if(TMPA<TMP)TMP=TMPA;
                tm+=TMP;
                c[i].tm-=TMP*a;
                TMP=c[i].tm/b;
                if(TMP>TMPB)TMP=TMPB;
                tm+=TMP;
                res=max(res,tm);
            }
        }
         if(true){
                    int k=rememb-1;
                    int TMP=k/a;
                    if(ctA<TMP)TMP=ctA;
                    int tm=TMP;
                    k-=TMP*a;
                    TMP=k/b;
                    if(ctB<TMP)TMP=ctB;
                    tm+=TMP;
                    res=max(res,tm);
                }
        cout<<res<<"\n";
    }
    return 0;
}