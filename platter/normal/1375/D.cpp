#include <bits/stdc++.h>
using namespace std;

int julde(int x) {
    return x>0?x:-x;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;

bool valid(int x,int y) {
    return x>=0&&x<n&&y>=0&&y<m;
}
int arr[1000];
int cnt[1001];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            cnt[arr[i]]++;
        }
        vector<int> ret;
        while (1) {
            int mex=0;
            while (cnt[mex]!=0) {
                mex++;
            }
            if (mex==n) {
                break;
            }
            ret.push_back(mex);
            cnt[arr[mex]]--;
            cnt[mex]++;
            arr[mex]=mex;
        }
        for(int i=n-1;i>=0;i--) {
            ret.push_back(i);
            if (arr[i]==i) {
                arr[i]++;
                continue;
            }
            for(int j=0;j<i;j++) {
                if (arr[j]==i) {
                    ret.push_back(j);
                    arr[j]=arr[i];
                    break;
                }
            }
            arr[i]=i+1;
        }
        printf("%d\n",ret.size());
        for(int i=0;i<ret.size();i++) {
            printf("%d ",ret[i]+1);
        }
        printf("\n");
    }
}