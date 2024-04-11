#include <stdio.h>
#include <map>
#include <set>

#define N 1000010

using namespace std;

map<int, int> all, sum, pos;
set<int> S;

int ls1[N], ls2[N];

int tree[2*N];
int arr[N], n;
long long ans = 0;
int cnt = 1;

void update(int idx) {
    while(idx < cnt) {
        tree[idx] += 1;
        idx += idx & (-idx);
    }
}
int query(int idx) {
    int ans = 0;
    while(idx) {
        ans += tree[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", &arr[i]);
        all[arr[i]]++;
    }
    for(int i = 0;i < n;i++) {
        sum[arr[i]]++;
        ls1[i] = sum[arr[i]];
        ls2[i] = all[arr[i]] - sum[arr[i]] + 1;
        S.insert(ls1[i]);
        S.insert(ls2[i]);
    }
    for(set<int>::iterator it = S.begin();it != S.end();it++) {
        pos[*it] = cnt++;   
    }
    for(int i = n-1;i>=0;i--) {
        ans += query(pos[ls1[i]]-1);
        update(pos[ls2[i]]);
    }
    printf("%I64d\n", ans);
    return 0;
}