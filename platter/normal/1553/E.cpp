#include <bits/stdc++.h>
using namespace std;

int cnt[300000];
int arr[300000];
int save[300000];
bool vis[300000];
int pos[300000];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int te=0;te<tc;te++) {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) {
            cnt[i]=0;
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            arr[i]--;
            save[i]=arr[i];
            pos[arr[i]]=i;
            cnt[(i-arr[i]+n)%n]++;
        }
        vector<int> vec; //
        for(int i=0;i<n;i++) {
            if (cnt[i]>=n/3) {
                vec.push_back(i);
            }
        }
        vector<int> v;
        for(int ind=0;ind<vec.size();ind++) {
            //printf(".%d\n",vec[ind]);
            for(int i=0;i<n;i++) {
                vis[i]=false;
                arr[i]=(i-vec[ind]+n)%n;
            }
            int ret=0;
            for(int i=0;i<n;i++) {
                int len=0;
                if (vis[i]) {
                    continue;
                }
                int now=i;
                while (len==0||now!=i) {
                    len++;
                    vis[now]=true;
                    now=pos[arr[now]];
                }
                ret+=len-1;
            }
            if (ret<=m) {
                v.push_back(vec[ind]);
            }
        }
        printf("%d ",v.size());
        for(int i=0;i<v.size();i++) {
            printf("%d ",v[i]);
        }
        printf("\n");
    }
    return 0;
}