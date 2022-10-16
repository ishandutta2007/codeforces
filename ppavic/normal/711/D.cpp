#include <cstdio>
#include <queue>
#include <iostream>

#define debag(x) cerr << #x << " = " << (x) << endl;


using namespace std;

typedef long long int llint;

const int N = 2e5 + 500;
const llint MOD = 1e9 + 7;

int deg[N],a[N],n,bio[N],notcik;
llint pot[N],sol = 1;
queue < int > s;

int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",a+i);
        deg[a[i]]++;
    }
    for(int i = 1;i<=n;i++)
        if(!deg[i])
            s.push(i);
    pot[0] = 1LL;
    for(int i = 1;i<N;i++)
        pot[i] = (2LL * pot[i-1]) % MOD;
    while(!s.empty()){
        int i = s.front();
        s.pop();
        deg[a[i]]--;
        bio[i] = 1;notcik++;
        if(!deg[a[i]])
            s.push(a[i]);
    }
    for(int i = 1;i<=n;i++){
        if( !bio[i]){
            int cik = 0,cur = i;
            while(!bio[cur]){
                cik++;
                bio[cur] = 1;
                cur = a[cur];
            }
            sol = (sol * (pot[cik] - 2LL)) % MOD;
            if(sol < 0) sol += MOD;
        }

    }
    printf("%I64d\n",(sol * pot[notcik]) % MOD);
}