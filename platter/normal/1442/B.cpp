#include <bits/stdc++.h>
using namespace std;

int arr[200000];
int b[200000];
bool used[200001];
int n,k;
const int mod=998244353;
int pr[200000];
int nt[200000];
int rev[200001];

bool checkleft(int pos) {
    if (pr[pos]==-1) {
        return false;
    }
    if (used[arr[pr[pos]]]) {
        return false;
    }
    return true;
}

bool checkright(int pos) {
    if (nt[pos]==-1) {
        return false;
    }
    if (used[arr[nt[pos]]]) {
        return false;
    }
    return true;
}

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            rev[arr[i]]=i;
        }
        for(int i=1;i<=n;i++) {
            used[i]=false;
        }
        for(int i=0;i<k;i++) {
            scanf("%d",&b[i]);
            used[b[i]]=true;
        }
        long long ret=1;
        for(int i=0;i<n-1;i++) {
            nt[i]=i+1;
        }
        nt[n-1]=-1;
        pr[0]=-1;
        for(int i=1;i<n;i++) {
            pr[i]=i-1;
        }
        for(int i=0;i<k;i++) {
            int pos=rev[b[i]];
            int val=checkleft(pos)+checkright(pos);
            if (val==0) {
                ret=0;
                break;
            }
            if (checkleft(pos)) {
                if (pr[pr[pos]]!=-1)
                    nt[pr[pr[pos]]]=pos;
                pr[pos]=pr[pr[pos]];
            }
            else {
                if (nt[nt[pos]]!=-1) {
                    pr[nt[nt[pos]]]=pos;
                }
                nt[pos]=nt[nt[pos]];
            }
            ret*=val;
            ret%=mod;
            used[b[i]]=false;
        }
        printf("%lld\n",ret);
    }
}