#include <bits/stdc++.h>
using namespace std;

int save[500000];
vector<int> ret;
const int mod=1e9+7;
vector<int> vec[500000];

int main(void) {
    int n,m;
    scanf("%d %d",&n,&m);
    memset(save,-1,sizeof(save));
    for(int i=0;i<n;i++) {
        int k;
        scanf("%d",&k);
        if (k==1) {
            int x;
            scanf("%d",&x);
            x--;
            if (save[x]==-1) {
                save[x]=-2;
                ret.push_back(i);
            }
            else if (save[x]>=0) {
                int now=save[x];
                for(int j=0;j<vec[now].size();j++) {
                    save[vec[now][j]]=-2;
                }
                ret.push_back(i);
            }
        }
        else {
            int a,b;
            scanf("%d %d",&a,&b);
            a--;
            b--;
            if (save[b]>=0) {
                swap(a,b);
            }
            if (save[a]==-2&&save[b]==-2) {
                continue;
            }
            if (save[a]==-2&&save[b]==-1) {
                ret.push_back(i);
                save[b]=-2;
                continue;
            }
            if (save[a]>=0&&save[b]<0) {
                if (save[b]==-1) {
                    save[b]=save[a];
                    vec[save[a]].push_back(b);
                }
                else {
                    int now=save[a];
                    for(int j=0;j<vec[now].size();j++) {
                        save[vec[now][j]]=-2;
                    }
                }
                ret.push_back(i);
                continue;
            }
            if (save[a]==-1&&save[b]==-2) {
                ret.push_back(i);
                save[a]=-2;
                continue;
            }
            if (save[a]==-1&&save[b]==-1) {
                vec[a].push_back(a);
                vec[a].push_back(b);
                save[a]=a;
                save[b]=a;
                ret.push_back(i);
                continue;
            }
            if (save[a]==save[b]) {
                continue;
            }
            ret.push_back(i);
            int one=save[a];
            int two=save[b];
            if (vec[one].size()<vec[two].size()) {
                swap(one,two);
            }
            for(int j=0;j<vec[two].size();j++) {
                vec[one].push_back(vec[two][j]);
                save[vec[two][j]]=one;
            }
        }
    }
    long long val=1;
    for(int i=0;i<ret.size();i++) {
        val*=2;
        val%=mod;
    }
    printf("%lld %d\n",val,ret.size());
    for(int i=0;i<ret.size();i++) {
        printf("%d ",ret[i]+1);
    }
}