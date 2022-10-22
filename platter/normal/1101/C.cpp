#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
typedef pair<P,int> Pi;
Pi arr[100000];
int group[100000];

bool comp(Pi a,Pi b) {
    if (a.first==b.first) {
        return a.second<b.second;
    }
    return a.first<b.first;
}

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            int s,e;
            scanf("%d %d\n",&s,&e);
            arr[i].first.first=s;
            arr[i].first.second=e;
            arr[i].second=i;
        }
        sort(arr,arr+n,comp);
        int end=-1e9;
        int now=1;
        bool right=false;
        for(int i=0;i<n;i++) {
            if (end<arr[i].first.first) {
                if (i!=0) {
                    right=true;
                }
                now^=1;
            }
            group[arr[i].second]=now+1;
            end=max(end,arr[i].first.second);
        }
        if (!right) {
            printf("-1\n");
            continue;
        }
        for(int i=0;i<n;i++) {
            printf("%d ",group[i]);
        }
        printf("\n");
    }
    return 0;
}