#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<int, int> idx[30];
char s1[200200], s2[200200];
int n, m, dp1[200200], dp2[200200];
int val1[200200], val2[200200];

int main(){
    scanf("%d %d", &n, &m);
    scanf("%s", s1);
    scanf("%s", s2);
    int ans=-1;
    int pt=0;
    for (int i=0;i<n;i++){
        if (pt<m && s1[i]==s2[pt]){
            pt++;
            val1[pt]=i+1;
        }
        dp1[i]=pt;
    }
    assert(pt==m);
    pt=m-1;
    for (int i=n-1;i>=0;i--){
        if (s1[i]==s2[pt]){
            val2[m-pt]=i+1;
            dp2[i]=m-pt;
            pt--;
        }
        else dp2[i]=m-pt;
    }
    for (int i=0;i<=m;i++){
        //printf("%d %d\n", val1[i], val2[i]);
        if (val1[i]==0 || val2[m-i]==0) continue;
        ans=max(ans, val2[m-i]-val1[i]);
    }
    printf("%d\n", ans);
    return 0;
}