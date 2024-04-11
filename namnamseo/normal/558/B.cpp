#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int data[100010];

vector<int> occ[1000010];

int aa, ab;

void app_ans(int a,int b){
    if(b-a<ab-aa) aa=a, ab=b;
}

int main()
{
    scanf("%d",&n);
    aa=0; ab=n-1;
    int i;
    int cm=0;
    for(i=0;i<n;++i) {
        scanf("%d",data+i);
        occ[data[i]].push_back(i);
        cm=max(cm,(int)occ[data[i]].size());
    }
    int j,sz;
    for(i=0;i<=1000000;++i){
        sz=occ[i].size();
        if(sz<cm) continue;
        for(j=0;j+cm-1<sz;++j){
            app_ans(occ[i][j],occ[i][j+cm-1]);
        }
    }
    printf("%d %d\n",aa+1,1+ab);
    return 0;
}