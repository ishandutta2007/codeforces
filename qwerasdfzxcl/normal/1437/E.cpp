#include <bits/stdc++.h>

using namespace std;
int input[500005];
int fix[500005];

int cal(int s, int e){
    if (input[s]>input[e]) return -1;
    vector<int> lis;
    lis.push_back(input[s]);
    for (int i=s+1;i<=e;i++){
        if (input[e]<input[i] || input[s]>input[i]) continue;
        if (lis.back()<=input[i]) lis.push_back(input[i]);
        else{
            int l=0, r=lis.size(), pos=0;
            while (l<r){
                int m=(l+r)/2;
                if (lis[m]<=input[i]){
                    pos=m+1;
                    l=m+1;
                }
                else r=m;
            }
            lis[pos]=input[i];
        }
        /*for (int j=0;j<lis.size();j++) printf("%d ", lis[j]);
        printf("\n");*/
    }
    return e-s+1-lis.size();
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=1;i<=n;i++) scanf("%d", &input[i]);
    input[0]=-1000000000;
    input[n+1]=2000000000;
    for (int i=0;i<=n+1;i++) input[i] -= i;
    for (int i=1;i<=k;i++) scanf("%d", &fix[i]);
    fix[0]=0;
    fix[k+1]=n+1;
    int ans=0;
    for (int i=0;i<=k;i++) {
        int tmp=cal(fix[i], fix[i+1]);
        if (tmp==-1){
            ans=-1;
            break;
        }
        ans += tmp;
    }
    printf("%d", ans);
    return 0;
}