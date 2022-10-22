#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
int leaf[262144];
const int sz=262144;

struct SegmentTree {
    int seg[524288];
    int sum(int l,int r,int node=1,int nodel=0,int noder=sz-1) {
        if (r<nodel||l>noder) {
            return -INF;
        }
        if (l<=nodel&&noder<=r) {
            return seg[node];
        }
        int mid=(nodel+noder)/2;
        return max(sum(l,r,node*2,nodel,mid),sum(l,r,node*2+1,mid+1,noder));
    }
    void update(int i,int val) {
        i+=sz;
        seg[i]=val;
        while (i>1) {
            i/=2;
            seg[i]=max(seg[i*2],seg[i*2+1]);
        }
    }
};

SegmentTree st;

int n,k;
int arr[200001];
vector<int> change;

int main(void) {
    scanf("%d %d\n",&n,&k);
    for(int i=1;i<sz*2;i++) {
        st.seg[i]=-INF;
    }
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d ",&x);
        leaf[x]++;
        st.update(x,x);
    }
    for(int i=1;i<=k;i++) {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<arr[k];i++)
        change.push_back(k);
    for(int i=k-1;i>=1;i--) {
        if (arr[i]!=arr[i+1]) {
            for(int j=0;j<arr[i]-arr[i+1];j++) {
                change.push_back(i);
            }
        }
    }
    int ret=0;
    int pick=0;
    vector<vector<int>> save;
    while (pick!=n) {
        ret++;
        vector<int> used;
        for(int i=0;i<change.size();i++) {
            int val=st.sum(1,change[i]);
            if (val!=-INF) {
                used.push_back(val);
                leaf[val]--;
                if (leaf[val]==0) {
                    st.update(val,-INF);
                }
                pick++;
            }
            else {
                break;
            }
        }
        save.push_back(used);
    }
    printf("%d\n",ret);
    for(int i=0;i<ret;i++) {
        printf("%d ",save[i].size());
        for(int j=0;j<save[i].size();j++) {
            printf("%d ",save[i][j]);
        }
        printf("\n");
    }
}