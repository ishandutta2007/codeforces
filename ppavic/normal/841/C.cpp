#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

const int N = 2e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;



int a[N],n,b[N],sol[N];
vector < int > ind,br;

bool cmp(int i,int j){
    return b[i] < b[j];
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie()
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",a + i);
        br.push_back(a[i]);
    }
     for(int i = 0;i<n;i++){
        scanf("%d",b + i);
        ind.push_back(i);
    }
    sort(br.rbegin(),br.rend());
    sort(ind.begin(),ind.end(),cmp);
    for(int i = 0;i<n;i++)
        sol[ind[i]] = br[i];
    for(int i = 0;i<n;i++){
        printf("%d ",sol[i]);
    }
    printf("\n");
}