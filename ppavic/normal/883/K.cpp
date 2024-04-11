#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int llint;

const int N = 2e5 + 500;

int dpl[N],dpr[N];
llint sol;
int l[N],r[N];
int n;
vector < int > prt;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d %d",l+i,r+i);
        sol -= l[i];
        r[i] += l[i];
    }
    dpl[n-1] = l[n-1];
    dpr[n-1] = r[n-1];
    for(int i = n-2;i>=0;i--){
        dpl[i] = max(l[i], dpl[i+1] - 1);
        dpr[i] = min(r[i], dpr[i+1] + 1);
        if(dpr[i] < dpl[i]){
            printf("-1\n");
            return 0;
        }
    }
    int st = dpr[0];
    sol += (llint)st;
    prt.push_back(st);
    for(int i = 1;i<n;i++){
        if(dpr[i-1] < st){
            printf("-1\n");
            return 0;
        }
        st = min(st + 1, dpr[i]);
        prt.push_back(st);
        sol += (llint)st;
    }
    printf("%I64d\n",sol);
    for(int i = 0;i<n;i++)
        printf("%d ",prt[i]);
    printf("\n");
}