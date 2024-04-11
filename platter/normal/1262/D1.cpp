#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
P arr[100];
int n;

bool compare(P a, P b) {
    if (a.first==b.first) {
        return a.second<b.second;
    }
    return a.first>b.first;
}

int main(void) {
    scanf("%d\n", &n);
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d ", &x);
        arr[i].first=x;
        arr[i].second=i;
    }
    sort(arr,arr+n,compare);
    int m;
    scanf("%d\n", &m);
    for(int i=0;i<m;i++) {
        int k,pos;
        int temp[100];
        scanf("%d %d\n", &k, &pos);
        for(int i=0;i<k;i++) {
            temp[i]=arr[i].second;
        }
        sort(temp,temp+k);
        for(int i=0;i<k;i++) {
            if (arr[i].second==temp[pos-1]) {
                printf("%d\n",arr[i].first);
                break;
            }
        }
    }
    return 0;
}