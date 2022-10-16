#include <cstdio>
#include <map>
#include <set>
#include <queue>

using namespace std;

const int N = 2e5 + 500;

queue < int > fre;

int n,a[N],uz[N],cnt[N];

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i = 1;i<=n;i++)
        if(!cnt[i]) fre.push(i);
    int sol = 0;
    for(int i = 0;i<n;i++){
        if(cnt[a[i]] == 1) continue;
        if(fre.front()> a[i] && !uz[a[i]]){
            uz[a[i]] = 1;
            continue;
        }
        cnt[a[i]]--;sol++;
        a[i] = fre.front();
        fre.pop();
    }
    printf("%d\n",sol);
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}